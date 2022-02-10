#include<bits/stdc++.h>

using namespace std;

const int maxn=1e3+2;
int n,m;//物品数量，m代表背包容量。
int w[maxn],v[maxn];

/* 
//朴素做法
//状态表示,dp[i][j]表示前i个物品背包体积不超过j的最大价值。
int dp[maxn][maxn];
//状态计算，dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i])
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            dp[i][j]=dp[i-1][j];//这一步要注意。
            if(j>=v[i])dp[i][j]=max(dp[i][j],dp[i-1][j-v[i]]+w[i]);
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
} */
/* 
//优化做法，优化空间。
int dp[maxn];
//状态表示，背包体积不超过j的最大价值。
//状态计算，dp[i][j]=max(dp[i][j],dp[i-1][j-v[i]]+w[i])从这入手。
//我们如果可以确保此时更新的dp[j]利用的dp[j-v[i]]是上一个状态的，那么就可以实现。
//即我们可以由V->0变化，这样就可以确保。
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=v[i];j--){
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[m]<<endl;
    return 0;
} */