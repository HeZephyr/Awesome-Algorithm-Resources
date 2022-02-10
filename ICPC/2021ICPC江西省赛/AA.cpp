/**
  *@filename:AA
  *@author: pursuit
  *@created: 2021-10-23 16:18
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 500 + 10, M = 1e4 + 10;
const int P = 998244353;
const int INF = 0x3f3f3f3f;

int n, m, p, q;
ll dp[2][N][N << 1], a[N][N];
void solve(){
}
int main(){	
    scanf("%d%d", &n, &m);
    scanf("%d%d", &p, &q);
    int op = 0, x;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            for(int k = 0; k < n + m; ++ k)dp[op][j][k] = 0;
            scanf("%d", &x);
            if(i == 1 && j == 1){
                if(x == 0)dp[op][j][1] = 1;
                else dp[op][j][0] = 1;
                continue;
            }
            if(x == 0){
                for(int k = 1; k < n + m; ++ k){
                    if(i == 1)dp[op][j][k] = (dp[op][j - 1][k - 1]) % P;
                    else if(j == 1)dp[op][j][k] = (dp[op ^ 1][j][k - 1]) % P;
                    else dp[op][j][k] = (dp[op][j - 1][k - 1] + dp[op ^ 1][j][k - 1]) % P;
                }
            }
            else{
                for(int k = 0; k < n + m; ++ k){
                    if(i == 1)dp[op][j][k] = (dp[op][j - 1][k]) % P;
                    else if(j == 1)dp[op][j][k] = (dp[op ^ 1][j][k]) % P;
                    else dp[op][j][k] = (dp[op][j - 1][k] + dp[op ^ 1][j][k]) % P;
                }
            }
        }
        op ^= 1;
    }
    ll res = 0;
    for(int k = p; k < n + m; ++ k){
        if(n + m - k - 1 >= q){
            //cout << "k:" << k << " " << dp[op ^ 1][m][k] << endl;
            res = (res + dp[op ^ 1][m][k]) % P;
        }
    }
    printf("%lld\n", res);
    return 0;
}