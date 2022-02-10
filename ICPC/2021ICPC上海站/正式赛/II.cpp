#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 205;


ll n, k;
ll a[N], t[N];
ll dp[N][6000][5][5];
ll dfs(int idx, int k, int sub){
    //不选。
    if(idx > n)return 0;
    if(!dp[idx][sub][0][k])dp[idx][sub][0][k] = dfs(idx + 1, k, sub);
    if(!dp[idx][sub][1][k])dp[idx][sub][1][k] = dfs(idx + 1, k, sub - t[idx]) + a[idx];
    if(!dp[idx][sub][2][k] && k > 0)dp[idx][sub][2][k] = dfs(idx + 1, k - 1, sub - 2 * t[idx]) + a[idx];
    if(!dp[idx][sub][3][k])dp[idx][sub][3][k] = dfs(idx + 1, k, sub + t[idx]) + a[idx];
    if(!dp[idx][sub][4][k] && k > 0)dp[idx][sub][4][k] = dfs(idx + 1, k, sub + 2 * t[idx]) + a[idx];
    return max({dp[idx][sub][0][k], dp[idx][sub][1][k], dp[idx][sub][2][k], dp[idx][sub][3][k], dp[idx][sub][4][k]});
}
/*
4 0
1000 8
-100 5
-100 5
-1 3
*/
int main(){
    scanf("%lld%lld", &n, &k);
    ll sum = 0;
    for(int i = 1;i <= n;i++){
        scanf("%lld %lld", &a[i], &t[i]);
        if(a[i] > 0)sum += a[i];
    }
    printf("%lld\n", sum);
    return 0;
    if(k >= 5){
        printf("%lld\n", sum);
    }
    else{
        dfs(1, k, 2700);
        ll maxx = 0;
        for(int i = 0; i <= 4; ++ i){
            for(int j = 0; j <= k; ++ j){
                maxx = max(maxx, dp[1][2700][i][j]);
            }
        }
        printf("%lld\n", maxx);
    }
    return 0;
}