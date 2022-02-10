/**
  *@filename:G-排列数
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-04 20:22
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 500 + 5;
const int P = 123456;

//动态规划。
int n,k;
int dp[N][N];//dp[i][j]表示前i个有j个折点的方案数。
void solve(){
    dp[1][0] = 1;
    for(int i = 2; i <= n; ++ i){
        dp[i][0] = 2;//这种方案就是从小到大递增或者从小到大递减。
        for(int j = 0; j <= i - 2; ++ j){
            //枚举可能的折点。由于有i个数，故最多有i - 2个折点。
            dp[i][j] %= P;
            dp[i + 1][j] += dp[i][j] * (j + 1);//这里我们需要注意，我们由于有i + 1个数，对于dp[i][j]
            //有j个折点，我们可以替换j + 1次得到。
            dp[i + 1][j + 1] += dp[i][j] * 2;//这里我们要多一个折点，就放在前面或者后面，则两种情况。
            dp[i + 1][j + 2] += dp[i][j] * (i - j - 2);//这里如果要想蹦到多了两个折点，则就是靠插入不是折点的点得到的。
            //而我们易知折点为j，最多为i - 2，故还剩下i - j - 2个可以变成折点的。
        }
    }
    printf("%d\n",dp[n][k - 1] % P);
}
int main(){
    scanf("%d %d", &n, &k);
    solve();
    return 0;
}