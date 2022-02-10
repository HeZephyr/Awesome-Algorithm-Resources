#include<bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;
//给定一个长度为n的数组a，将数组分成k段，每段的价值为最大值减去最小值，数组的价值为每段价值之和，问k=1,...n时的最大价值。
int n, a[N], dp[2][N][4];//dp[i][j][0/1/2]表示前i个数，分成j段，且第j个段：0表示未选最小值最大值。1表示已选择最小值，2表示已选择最大值。3表示已选完。
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    dp[0][0][3] = 0;
    int op = 1;
    for(int i = 1; i <= n; ++ i){
        //枚举每个数。
        for(int j = 1; j <= i; ++ j){
            dp[op][j][0] = max(dp[op ^ 1][j - 1][3], dp[op ^ 1][j][0]);
            dp[op][j][1] = max(dp[op ^ 1][j][0] - a[i], dp[op ^ 1][j][1]);
            dp[op][j][2] = max(dp[op ^ 1][j][2], dp[op ^ 1][j][0] + a[i]);
            dp[op][j][3] = max(dp[op ^ 1][j][3], max(dp[op][j][2] - a[i], dp[op][j][1] + a[i]));
        }
        op ^= 1;
    }
    op ^= 1;
    for(int i = 1; i <= n; ++ i){
        printf("%d\n", dp[op][i][3]);
    }
    return 0;
}