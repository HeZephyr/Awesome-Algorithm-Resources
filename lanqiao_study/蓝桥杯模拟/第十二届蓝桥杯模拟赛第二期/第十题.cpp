/**
  *@filename:第十题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-14 12:28
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,m;
int dp[105][105];//dp[i][j]表示从(1,1)走到(i,j)的最大权值之和。一步走的直线距离不能超过3.
int a[105][105];
int go[9][2]={{0,-1},{0,-2},{0,-3},{-1,0},{-2,0},{-3,0},{-1,-1},{-2,-1},{-1,-2}};
void solve(){
    memset(dp,0,sizeof(dp));
    dp[1][1]=a[1][1];//确定起始状态。
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<9;k++){
                //状态转移确定。
                int tx=i+go[k][0],ty=j+go[k][1];
                if(tx>=1&&tx<=n&&ty>=1&&ty<=m){
                    dp[i][j]=max(dp[i][j],dp[tx][ty]+a[i][j]);
                }
            }
        }
    }
    cout<<dp[n][m]<<endl;
}
int main(){
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        solve();
    }
    return 0;
}