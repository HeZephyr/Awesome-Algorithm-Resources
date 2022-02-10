/**
  *@filename:股票买卖V
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-26 21:22
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,x;//这次无非就是多加了一个是否处于冷冻期的状态。
int f[N][2][2];//其中f[i][0][0]表示前i个股票，当前未持股，且不处于冷冻期的最大收益。其他同理。
//则易知：
//f[i][0][0] = f[i - 1][0][0];
//f[i][0][1] = f[i - 1][1][0] + x;
//f[i][1][0] = max(f[i - 1][1][0],f[i - 1][0][0] - x);
//f[i][1][1]，该状态不成立，因为持股和冷冻期存在矛盾。
void solve(){
}
int main(){
    scanf("%d", &n);
    fill(f[0][0],f[0][0] + N * 2 * 2,-0x3f3f3f);
    for(int i = 0; i <= n; i++){
        f[i][0][0] = 0;
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        f[i][0][0] = max(f[i - 1][0][0],f[i - 1][0][1]);
        f[i][0][1] = f[i - 1][1][0] + x;
        f[i][1][0] = max(f[i - 1][1][0],f[i - 1][0][0] - x);
    }
    int maxx = max(f[n][0][0],f[n][0][1]);
    printf("%d\n",maxx);
    solve();
    return 0;
}