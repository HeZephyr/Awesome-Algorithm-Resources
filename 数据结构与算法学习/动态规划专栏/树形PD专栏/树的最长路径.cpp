/**
  *@filename:树的最长路径
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-25 20:18
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 10000 + 5;
const int P = 1e9+7;

int n;
struct node{
    int v,next,w;
}edges[N << 1];
int tot,head[N];
void add(int u,int v,int w){
    edges[++tot].v = v;
    edges[tot].w = w;
    edges[tot].next = head[u];
    head[u] = tot;
}
ll ans = 0,f[N];
void dfs(int u,int fu){
    ll premax = 0;//记录之前的最大值。
    for(int i = head[u]; i; i = edges[i].next){
        int v = edges[i].v,w = edges[i].w;
        if(v == fu)continue;
        dfs(v,u);
        ans = max(ans,premax + f[v] + w);
        premax = max(premax,f[v] + w);//实际上就是记录次大值。而ans记录全局解。
    }
    f[u] = premax;
}
void solve(){
    dfs(1,-1);//从1出发。
    printf("%lld\n",ans);
}
int main(){
    scanf("%d",&n);
    int u,v,w;
    for(int i = 1; i < n; i++){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    solve();
    return 0;
}