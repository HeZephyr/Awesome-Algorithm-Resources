/**
  *@filename:股票买卖II
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-26 21:30
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,x;
int f[N][2];//f[i][0]表示在前i个股票，且当前为未持股票的最大收益，而f[i][1]表示在前i个股票中，且当前已持股票的最大收益。
void solve(){
}
int main(){
    scanf("%d", &n);
    fill(f[0],f[0] + N * 2,-0x3f3f3f);
    for(int i = 0; i <= n; i++)f[i][0] = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        f[i][0] = max(f[i - 1][0],f[i - 1][1] + x);
        f[i][1] = max(f[i - 1][1],f[i - 1][0] - x);
    }
    printf("%d\n",f[n][0]);
    solve();
    return 0;
}