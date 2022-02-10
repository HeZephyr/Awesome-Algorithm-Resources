#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const double eps = 1e-12;
int t;
double p, res;
double dp[3100][210];
double dfs(int i, int q){
    //win
    if(i >= 3000)return 0;
    if(dp[i][q] > 0)return dp[i][q];
    return dp[i][q] = i * 1.0 * p * q / 20000 + 
    dfs(i + 1, min(200, q + 4)) * p * (200 - q) / 20000 + 
    dfs(i + 1, min(200, q + 3)) * (100 - p) / 100;
}
int main(){
    scanf("%d", &t);
    for(int k = 1; k <= t; ++ k){
        res = 0;
        memset(dp, 0, sizeof(dp));
        scanf("%lf", &p);
        printf("Case %d: ", k);
        dfs(1, 4);
        printf("%.10lf\n", dp[1][4]);
    }
    return 0;
}