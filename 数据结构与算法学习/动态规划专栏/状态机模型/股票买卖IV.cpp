/**
  *@filename:股票买卖IV
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-26 20:22
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5,K = 110;
const int P = 1e9+7;

int n,k,x;
int f[N][K][2];//我们用f[i][j][0]表示在前i个股票中，买卖了j次，且当前状态没有股票。
//而f[i][j][1]则表示在前i个股票中，买卖了j次，且当前状态有股票。则状态转移方程易知。
//需要知道的是，我们一次买入卖出和为一笔交易，但是我们必须将买入股票的时候做为一次交易处理，其他的作为条件即可。
//所以说我们状态转移方程如下：
//f[i][j][0] = max(f[i - 1][j][0],f[i - 1][j][1] + x);//当前状态为0，说明没有股票，要没是卖出了，要么是没有管。
//f[i][j][1] = max(f[i - 1][j][1],f[i - 1][j - 1][0] - x);//当前状态为1，说明有股票，则要么是没买入，要么是买入现在的。
void solve(){
}
int main(){
    scanf("%d%d", &n, &k);
    fill(f[0][0],f[0][0] + N * K * 2,-0x3f3f3f);
    for(int i = 0; i <= n; i++)f[i][0][0] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        for(int j = 1;j <= k; j++){
            f[i][j][0] = max(f[i - 1][j][0],f[i - 1][j][1] + x);//卖出一只股票。
            f[i][j][1] = max(f[i - 1][j][1],f[i - 1][j - 1][0] - x);//这是买入，我们买入股票的时候必须要按照一次交易处理。
        }
    }
    int maxx = 0;
    for(int j = 0; j <= k; j++){
        maxx = max(maxx,f[n][j][0]);
    }
    printf("%d\n", maxx);
    solve();
    return 0;
}