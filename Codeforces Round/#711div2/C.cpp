/**
  *@filename:C
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-30 15:37
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000 + 5;
const int mod = 1e9+7;

int t,n,k;//n个平面，k表示为衰变年龄。
int dp[maxn][maxn];//定义状态：用dp[i][j]表示运动前方还有k个平面，且衰变年龄为j的粒子所能产生的粒子数量。
void solve(){
    memset(dp,0,sizeof(dp));
    //初始状态，对于衰变年龄为1的粒子，它不过经过多少个平面，所能产生的粒子就是它本身。
    for(int i=1;i<=n;i++){
        dp[i][1]=1;
    }
    //对于运动前方没有平面的粒子，是不能分裂的。粒子数量只有它本身。
    for(int j=1;j<=k;j++){
        dp[0][j]=1;
    }
    //为了通过前面状态得到后面状态，所以我们先要推出j的所有情况。
    for(int j=1;j<=k;j++){
        for(int i=1;i<=n;i++){
            dp[i][j]=(dp[i-1][j]+dp[n-i][j-1])%mod;
        }
    }
    cout<<dp[n][k]<<endl;
}
int main() {
    while(cin>>t){
        while(t--){
            cin>>n>>k;
            solve();
        }
    }
    return 0;
}