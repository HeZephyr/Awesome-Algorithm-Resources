/**
  *@filename:STA_Station
  *@author: pursuit
  *@created: 2021-11-01 21:13
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

/*
换根dp套路：
1. 指定某个节点为根节点。
2. 第一次搜索完成预处理（如子树的大小等），同时得到该节点的解。
3. 第二次搜索进行换根的动态规划，由已知解的节点退出相连节点的解。
*/
int n, siz[N], dep[N];
ll res[N];
struct node{
    int to, next;
}edges[N << 1];
int head[N], tot;
void add(int u, int v){
    edges[++ tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void dfs1(int u, int fu){
    dep[u] = dep[fu] + 1;
    siz[u] = 1;
    for(int i = head[u], v; i; i = edges[i].next){
        v = edges[i].to;
        if(v == fu)continue;
        dfs1(v, u);
        siz[u] += siz[v];
    }
}
void dfs2(int u, int fu){
    for(int i = head[u], v; i; i = edges[i].next){
        v = edges[i].to;
        if(v == fu)continue;
        res[v] = res[u] + siz[1] - 2 * siz[v];
        dfs2(v, u);
    }
}
void solve(){
    dfs1(1, 0);
    for(int i = 1; i <= n; ++ i){
        res[1] += dep[i];
    }
    dfs2(1, 0);
    ll maxx = res[1];
    int idx = 1;
    for(int i = 2; i <= n; ++ i){
        if(res[i] > maxx){
            maxx = res[i];
            idx = i;
        }
    }
    printf("%d\n", idx);
}
int main(){	
    scanf("%d", &n);
    for(int i = 1, u, v; i < n; ++ i){
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
    solve();
    return 0;
}