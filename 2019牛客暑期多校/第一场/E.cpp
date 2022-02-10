/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-10-15 17:25
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m;
int dp[N][N];
void solve(){
    cout << dp[n + m][n + m] << endl;
}
int main(){	
    while(cin >> n >> m){
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 0; i <= n + m; ++ i){
            for(int j = 0; j <= n + m; ++ j){
                if(i - j <= n && i){
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % P;
                }
                if(j - i <= m && j){
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % P;
                }
            }
        }
        solve();
    }
    return 0;
}