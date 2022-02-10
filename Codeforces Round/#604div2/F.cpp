/**
  *@filename:F
  *@author: pursuit
  *@created: 2021-08-09 19:30
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e3 + 10;
const int P = 998244353;
const int INF = 0x3f3f3f3f;

int n,dp[N][N],f[N];
char s[N];
int qsm(int n,int q = P - 2){
    int ans = 1;
    while(q){
        if(q & 1){
            ans = 1LL * ans * n % P;
        }
        n = 1LL * n * n % P;
        q >>= 1;
    }
    return ans;
}
void solve(){
    n = strlen(s);
    //初始化f数组。
    for(int i = 0; i < n; ++ i){
        f[i + 1] = f[i] + (s[i] == '?');
    }
    //枚举区间长度。
    for(int len = 2; len <= n; ++ len){
        //枚举区间左端点。
        for(int i = 0; i + len - 1 < n; ++ i){
            int j = i + len - 1;
            if(s[i] != '('){
                dp[i][j] = (dp[i][j] + dp[i + 1][j]) % P;
            }
            if(s[j] != ')'){
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % P;
            }
            if(s[i] != '(' && s[j] != ')'){
                dp[i][j] = (1LL * dp[i][j] - dp[i + 1][j - 1] + P) % P;
            }
            if(s[i] != ')' && s[j] != '('){
                dp[i][j] = (1LL * dp[i][j] + dp[i + 1][j - 1] + qsm(2,f[j] - f[i + 1])) % P;
            }
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    printf("%d\n", dp[0][n - 1]);
}
int main(){
    scanf("%s", s);	
    solve();
    return 0;
}