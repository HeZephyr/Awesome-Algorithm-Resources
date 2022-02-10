/**
  *@filename:C_Parsa_s_Humongous_Tree
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-25 12:30
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,l[N],r[N];
ll dp[N][2];
struct node{
    int v,next;
}edges[N << 1];
int tot,head[N];
void add(int u,int v){
    edges[++tot].v = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void dfs(int u,int fu){
    for(int i = head[u]; i; i = edges[i].next){
        int v = edges[i].v;
        if(v == fu)continue;//避免自环。
        dfs(v,u);//先更新子树。再往上更新根节点。
        dp[u][0] += max(dp[v][0] + abs(l[u] - l[v]),dp[v][1] + abs(l[u] - r[v]));
        dp[u][1] += max(dp[v][0] + abs(r[u] - l[v]),dp[v][1] + abs(r[u] - r[v]));
    }
}
void solve(){
    dfs(1,-1);
    printf("%lld\n",max(dp[1][0],dp[1][1]));
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 1; i <= n; i++){
            scanf("%d %d",&l[i],&r[i]);
        }
        memset(head,0,sizeof(head));
        memset(dp,0,sizeof(dp));
        tot = 0;
        int u,v;
        for(int i = 1; i < n; i++){
            scanf("%d %d",&u,&v);
            add(u,v),add(v,u);
        }
        solve();
    }
    return 0;
}