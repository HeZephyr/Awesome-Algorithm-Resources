/**
  *@filename:能量项链
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-18 16:19
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200 + 5;
const int P = 1e9+7;

int n;
int a[N];
int dp[N][N];//dp[l,r]表示在[l,r]这段区间所能释放的最大能量。
void solve(){
    memset(dp,0,sizeof(dp));
    for(int len=3;len<=n+1;len++){
        //这里从3开始，才可以枚举两个项链连接。
        //枚举起点。
        for(int l=1;l+len-1<=2*n;l++){
            int r=l+len-1;
            //枚举分割点。
            for(int k=l+1;k<r;k++){
                dp[l][r]=max(dp[l][r],dp[l][k]+dp[k][r]+a[l]*a[k]*a[r]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i][i+n]);
    }
    cout<<ans<<endl;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    solve();
    return 0;
}