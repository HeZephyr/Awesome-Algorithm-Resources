/**
  *@filename:D_Maximum_Sum_of_Products
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-30 10:34
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 5000 + 5;
const int mod = 1e9+7;

int n;
ll a[maxn],b[maxn],dp[maxn][maxn],s[maxn];//区间dp。dp[l][r]即表示的是翻转区间[l,r]之后这段区间ai*bi的最大值。
//则易知状态转移方程为d[i][j]=dp[i+1][j-1]+a[i]*b[j]+a[j]*b[i];
void solve(){
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i]*b[i];//记录前缀和，便于之后操作。
    }
    //初始化，只翻转一个数的时候，即等于没有翻转。
    for(int i=1;i<=n;i++){
        dp[i][i]=a[i]*b[i];
    }
    //枚举左右端点。
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            //注意这里的i必须是从大到小，因为我们的j会用到i+1。
            dp[i][j]=max(dp[i][j],dp[i+1][j-1]+a[i]*b[j]+a[j]*b[i]);
        }
    }
    //所有状态更新完之后开始取max。
    ll ans=s[n];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans=max(ans,dp[i][j]+s[i-1]+s[n]-s[j]);
        }
    }
    cout<<ans<<endl;
    solve();
    return 0;
}