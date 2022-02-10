#include<bits/stdc++.h>
#define ll long long 

const int N = 1e3 + 5;
const int P = 1e9 + 7;
using namespace std;
ll dp[N][N][4];
int main(){
    ll n, m;
    while(~scanf("%lld%lld", &n, &m)){
    dp[1][1][0] = dp[1][1][1] = dp[1][1][2] = 1ll;
    for(int j = 2;j <= m;j++){
        dp[1][j][0] = dp[1][j-1][0];
        dp[1][j][1] = (dp[1][j-1][0] + dp[1][j-1][1])%P;
        dp[1][j][2] = (dp[1][j-1][0] + dp[1][j-1][1] + dp[1][j-1][2])%P;
    }
    for(int i = 2;i <= n;i++){
        dp[i][1][0] = dp[i-1][1][0];
        dp[i][1][1] = (dp[i-1][1][0] + dp[i-1][1][1])%P;
        dp[i][1][2] = (dp[i-1][1][0] + dp[i-1][1][1] + dp[i-1][1][2])%P;
    }
    for(int i = 2;i <= n;i++){
        for(int j = 2;j <= n;j++){
            dp[i][j][0] = 1ll;
            dp[i][j][1] = (dp[i-1][j][1]*dp[i][j-1][1]%P + 1ll)%P;
            dp[i][j][2] = (dp[i-1][j][2]*dp[i][j-1][2]%P + dp[i][j][1])%P;
        }
    }
    printf("%lld\n", (dp[n][m][0]+dp[n][m][1]+dp[n][m][2])%P);
    }
}