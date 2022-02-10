/**
  *@filename:D
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-25 16:39
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000 + 5;
const int P = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f;

int n,m,c;
ll a[N][N],dp[N][N],ans[N][N];//其中dp[i][j]表示已经建了一站。且当前处于(i,j)。ans[i][j]则表示最后一站在(i,j)处建的最低成本。
void solve(){
    fill(dp[0],dp[0] + N * N,INF);
    fill(ans[0],ans[0] + N * N,INF);
    //从(1,1)开始往右下走。
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            dp[i][j] = min(a[i][j],min(dp[i - 1][j],dp[i][j - 1]) + c);//设状态转移方程。
        }
    }
    ll minn = INF;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            ans[i][j] = min(dp[i - 1][j],dp[i][j - 1]) + c + a[i][j];
            minn = min(ans[i][j],minn);
        }
    }
    //从(n,m)开始往左上走。
    for(int i = n; i >= 1; -- i){
        for(int j = 1; j <= m; ++ j){
            dp[i][j] = min(a[i][j],min(dp[i + 1][j],dp[i][j - 1]) + c);
        }
    }
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            ans[i][j] = min(dp[i + 1][j],dp[i][j - 1]) + c + a[i][j];
            minn = min(ans[i][j],minn);
        }
    }
    printf("%lld\n",minn);
}
int main(){
    scanf("%d%d%d", &n, &m, &c);
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            scanf("%lld", &a[i][j]);
        }
    }
    solve();
    return 0;
}