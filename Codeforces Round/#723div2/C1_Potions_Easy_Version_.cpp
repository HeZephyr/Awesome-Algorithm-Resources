/**
  *@filename:C1_Potions_Easy_Version_
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-28 22:42
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2000 + 5;
const int P = 1e9+7;

int n,a[N];
ll dp[N][N];//dp[i][j][0]表示前i瓶已经喝了j瓶,此时你的体力。如果为负数则淘汰。
void solve(){
    fill(dp[0],dp[0] + N * N,-0x3f3f3f3f);
    for(int i = 0; i <= n; ++ i){
        dp[i][0] = 0;
    }
    //状态转移，dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - 1] + a[i])
    for(int i = 1; i <= n; ++ i){
        for(int j = 1;j <= i; ++ j){
            if(dp[i - 1][j - 1] >= 0){
                dp[i][j] = max(dp[i - 1][j - 1] + a[i],dp[i][j]);
            }
            if(dp[i - 1][j] >= 0){
                dp[i][j] = max(dp[i - 1][j],dp[i][j]);
            }
        }
    }
    for(int j = n; j >= 0; -- j){
        if(dp[n][j] >= 0){
            cout << j <<endl;
            break;
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    solve();
    return 0;
}