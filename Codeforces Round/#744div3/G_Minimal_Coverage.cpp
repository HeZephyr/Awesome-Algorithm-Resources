/**
  *@filename:G_Minimal_Coverage
  *@author: pursuit
  *@created: 2021-09-29 20:05
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e4 + 10, M = 2010;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N];
int dp[N][M];//dp[i][j]表示的是前i个线段，且结束位置为j的线段长度。
void solve(){
    dp[1][a[1]] = a[1];
    for(int i = 2; i <= n; ++ i){
        for(int j = 0; j < M; ++ j){
            if(j <= a[i]){
                dp[i][0] = min(dp[i][0], dp[i - 1][j] + a[i] - j);
            }
            else{
                dp[i][j - a[i]] = min(dp[i][j - a[i]], dp[i - 1][j]);
            }
            dp[i][j + a[i]] = min(dp[i][j + a[i]], max(dp[i - 1][j], j + a[i]));
        }
    }
    int res = INF;
    for(int j = 0; j < M; ++ j){
        res = min(res, dp[n][j]);
    }
    printf("%d\n", res);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            for(int j = 0; j < M; ++ j){
                dp[i][j] = INF;
            }
        }
        solve();
    }
    return 0;
}