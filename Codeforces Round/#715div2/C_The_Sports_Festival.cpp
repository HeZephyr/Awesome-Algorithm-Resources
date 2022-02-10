/**
  *@filename:C_The_Sports_Festival
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-16 23:05
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 2000 + 5;
const int mod = 1e9+7;

int n;
int a[maxn];
ll dp[maxn][maxn];
void solve(){
    //为了更好的处理，我们需要先对数组进行升序排列，这样可以好确定最小值和最大值。
    sort(a,a+n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=1e12;//初始dp数组保留最大值。
        }
    }
    //初始化dp数组。
    dp[0][0]=a[n-1]-a[0];//这是毋庸置疑的。
    for(int i=1;i<n;i++){
        //只删除最大值i次
        dp[i][0]=dp[i-1][0]+a[n-i-1]-a[0];//删除最大值从右边删除，那么删除之后当前最大值就是a[n-i-1];
        //只删除最小值i次
        dp[0][i]=dp[0][i-1]+a[n-1]-a[i];//删除最小值从左边删除，那么删除之后当前最小值就是a[i]。
    }
    //接下来开始进行状态转移取最优。
    for(int i=1;i<n;i++){
        for(int j=1;i+j<n;j++){
            //i+j不得超过n次。
            dp[i][j]=min(dp[i][j],dp[i-1][j]+a[n-i-1]-a[j]);//选择删除最大值
            dp[i][j]=min(dp[i][j],dp[i][j-1]+a[n-i-1]-a[j]);//选择删除最小值
      }
    }
    ll res=1e12;
    for(int i=0;i<n;i++){
        res=min(res,dp[i][n-i-1]);
    }
    cout<<res<<endl;
}
int main(){
    while(cin>>n){
        for(int i=0;i<n;i++)cin>>a[i];
        solve();
    }
    return 0;
}