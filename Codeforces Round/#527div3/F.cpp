/**
  *@filename:F
  *@author: pursuit
  *@created: 2021-08-29 15:55
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

struct edge{
    int to,next;
}edges[N << 1];
int head[N],tot;
int n,a[N];
ll res,sum[N];//sum[u]表示以u为根结点的子树点权和。
void add(int u,int v){
    edges[++ tot].next = head[u];
    edges[tot].to = v;
    head[u] = tot;
}
void dfs1(int u,int fu,int depth){
    res += 1LL * depth * a[u];
    sum[u] = a[u];
    for(int i = head[u]; i; i = edges[i].next){
        int v = edges[i].to;
        if(v == fu)continue;
        dfs1(v,u,depth + 1);
        sum[u] += sum[v];
    }
}
void dfs2(int u,int fu,ll ans){
    res = max(res,ans);
    for(int i = head[u]; i; i = edges[i].next){
        int v = edges[i].to;
        if(v == fu)continue;
        ll temp = ans + sum[u] - 2 * sum[v];
        sum[u] -= sum[v];
        sum[v] += sum[u];
        dfs2(v,u,temp);
        sum[v] -= sum[u];
        sum[u] += sum[v];
    }
}
void solve(){
    dfs1(1,-1,0);
    dfs2(1,-1,res);
    printf("%lld\n", res);
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    int u,v;
    for(int i = 1; i < n; ++ i){
        scanf("%d%d", &u, &v);
        add(u,v), add(v,u);
    }
    solve();
    return 0;
}