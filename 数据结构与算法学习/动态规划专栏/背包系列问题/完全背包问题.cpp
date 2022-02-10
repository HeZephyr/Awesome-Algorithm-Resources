#include<bits/stdc++.h>

using namespace std;

const int maxn=1e3+10;
int n,m;
int v[maxn],w[maxn];
//状态定义，我们同样是根据用dp[i][j]来表示前i个物品，选取体积不超过j的最大价值。
//状态计算，dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i],dp[i-1][j-2*v[i]]+2*w[i],...,dp[i-1][j-k*v[i]]+k*w[i]);
//我们发现，此时这种情况是特别多且繁杂的，如果我们去枚举k的话必然会超时。我们再来代换一下
//dp[i][j-v[i]]=max(dp[i-1][j-v[i]],dp[i-1][j-2*v[i]]+w[i],...,dp[i-1][j-k*v[i]]+(k-1)*w[i])
//我们发现，这种状态其实就是上面这个状态减去一个w[i].所以我们可以得到
//dp[i][j]=max(dp[i-1][j],dp[i][j-v[i]]+w[i])，此时我们发现这个和01背包状态计算只是i-1变成i了。
//为了使得我们利用的i是现在这一层的i，我们必须从0->V枚举。这样我们同样可以在这上面做空间优化，当然也可以不优化。

/*
//朴素做法。 
int dp[maxn][maxn];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=v[i]){
                dp[i][j]=max(dp[i][j],dp[i][j-v[i]]+w[i]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
} 
*/
//空间优化。
int dp[maxn];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j>=v[i]){
                dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
            }
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}