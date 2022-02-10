/**
  *@filename:数字转换
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-25 21:47
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 50000 + 5;
const int P = 1e9+7;

struct node{
    int v,next;
}edges[N];
int tot,head[N];
int n;
int sum[N];//sum[i]求解的是i的约数之和。
int f[N][2];//f[i][0]表示i往下走的最长路径，而f[i][1]表示i往下走的次长路径，那么结果就是f[i][0] + f[i][1].
int ans = 0;
void init(){
    for(int i = 1; i <= n; i++){
        for(int j = 2; j <= n / i; j++){
            sum[i * j] += i;
        }
    }
}
void add(int u,int v){
    edges[++tot].v = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void dfs(int u,int fu){
    for(int i = head[u]; i; i = edges[i].next){
        int v = edges[i].v;
        if(v == fu)continue;
        dfs(v,u);
        if(f[u][0] <= f[v][0] + 1){
            f[u][1] = f[u][0];
            f[u][0] = f[v][0] + 1;
        }
        else if(f[u][1] < f[v][0] + 1){
            f[u][1] = f[v][0] + 1;
        }
        //printf("%d -> %d:%d\n",u,v,max(f[u][0],f[u][1]));
    }
    ans = max(ans,f[u][0] + f[u][1]);
}
void solve(){
    dfs(1,-1);
    printf("%d\n",ans);
}
int main(){
    scanf("%d",&n);
    init();
    for(int i = 2;i <= n; i++){
        //从小到大加。
        if(sum[i] < i){
            add(sum[i],i);
        }
    }
    solve();
    return 0;
}