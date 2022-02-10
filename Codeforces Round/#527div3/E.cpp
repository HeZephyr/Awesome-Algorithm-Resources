/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-08-29 15:18
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

/*
任务是向图中添加一些边，使其成为一棵树且树的直径尽可能小。
找到所有树的重心，再合并在一起即可。
*/
struct edge{
    int to, next;
} edges[N];
int head[N],tot;
int n,m,belong[N],cnt;
int ans1[N],ans2[N],in[N];//ans[i]表示第i个连通块的最小的最大直径。in[i]表示第i个连通块的中心点。
int id[N];
void add(int u,int v){
    edges[++ tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
bool cmp(int i,int j){
    return ans1[i] > ans1[j];
}
void dfs1(int u){
    belong[u] = cnt;
    for(int i = head[u]; i; i = edges[i].next){
        int v = edges[i].to;
        if(!belong[v])dfs1(v);
    }
}
int dfs2(int u,int fu,int depth){
    int maxx = depth;
    for(int i = head[u]; i; i = edges[i].next){
        int v = edges[i].to;
        if(v == fu)continue;
        maxx = max(maxx,dfs2(v,u,depth + 1));
    }
    return maxx;
}
void solve(){
    //确定每个结点所属的连通分量。
    fill(ans1, ans1 + N, INF);
    for(int i = 1; i <= n; ++ i){
        if(!belong[i]){
            ++ cnt;
            dfs1(i);
        }
    }
    for(int i = 1; i <= n; ++ i){
        int maxx = dfs2(i,-1,0);
        //cout << i << " " << maxx << endl;
        if(maxx < ans1[belong[i]]){
            ans1[belong[i]] = maxx;
            //保存中心点。
            in[belong[i]] = i;
        }
        ans2[belong[i]] = max(ans2[belong[i]], maxx);
    }
    int res = 0;
    for(int i = 1; i <= cnt; ++ i){
        id[i] = i;
        res = max(res,ans2[i]);
    }
    sort(id + 1, id + 1 + cnt,cmp);
    if(cnt >= 2){
        res = max(res, ans1[id[1]] + ans1[id[2]] + 1);
    }
    if(cnt >= 3){
        res = max(res, ans1[id[2]] + ans1[id[3]] + 2);
    }
    printf("%d\n", res);
    for(int i = 2; i <= cnt; ++ i){
        printf("%d %d\n", in[id[1]], in[id[i]]);
    }
}
int main(){	
    scanf("%d%d", &n, &m);
    int u,v;
    for (int i = 1; i <= m; ++ i){
        scanf("%d%d", &u, &v);
        add(u,v), add(v,u);
    }
    solve();
    return 0;
}