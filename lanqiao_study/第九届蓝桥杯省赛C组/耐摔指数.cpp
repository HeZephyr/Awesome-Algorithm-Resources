/**
  *@filename:耐摔指数
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-10 00:20
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 10000 + 5;
const int mod = 1e9+7;

int n;
int dp[4][maxn];//dp[i][j]表示有i部手机且待测j个楼层的运气最差的最少测试次数。
void solve(){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            //不管有几部手机，最坏的次数就是从1到j测下去。
            dp[i][j]=j;
        }
    }
    //接下来开始模拟，
    for(int i=2;i<=3;i++){
        for(int j=1;j<=n;j++){
            //模拟1~j的测试情况。
            //如果坏了,则手机数量减1，并去下一层测试，否则没摔坏就去楼上测试。
            for(int k=1;k<j;k++){
                dp[i][j]=min(dp[i][j],max(dp[i-1][k-1],dp[i][j-k])+1);
            }
        }
    }
    cout<<dp[3][n]<<endl;
}
int main(){
    while(cin>>n){
        solve();
    }
    return 0;
}