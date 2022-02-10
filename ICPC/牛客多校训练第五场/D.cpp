/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-08-06 16:53
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 5e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int fac[N << 1],inv[N << 1];
//求解一段相同的前缀 + 一个不同的字符（且该字符需要比第二个小） + 任意长度的后缀
int dp[N][N];//dp[i][j]表示第一个字符串前i个位置和第二个字符串前j个位置所具有的相同的子序列。
char a[N],b[N];
int qsm(int n,int q){
    int ans = 1;
    while(q){
        if(q & 1)ans = 1LL * ans * n % P;
        n = 1LL * n * n % P;
        q >>= 1;
    }
    return ans;
}
void init(){
    fac[0] = fac[1] = 1;
    for(int i = 2; i < N * 2; ++ i){
        fac[i] = 1LL * fac[i - 1] * i % P;
    }
    inv[N * 2 - 1] = qsm(fac[N * 2 - 1],P - 2);
    for(int i = N * 2 - 2; i >= 0; -- i){
        inv[i] = 1LL * inv[i + 1] * (i + 1) % P;
    }
}
int C(int n,int m){
    return 1LL * fac[n] * inv[m] % P * inv[n - m] % P;
}
void solve(){
    int n = strlen(a + 1), m = strlen(b + 1);
    for(int i = 0; i <= n; ++ i)dp[i][0] = 1;
    for(int j = 0; j <= m; ++ j)dp[0][j] = 1;
    int ans = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            //不考虑a[i]和b[j]关系的状态转移，此时由于前i-1，前j个和前i，前j-1个都包含了i-1，j-1，故需要减去。
            dp[i][j] = ((dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) % P + P) % P;
            if(a[i] == b[j])dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % P;
            else if(a[i] < b[j]){
                //说明我们找到了分割点。
                ans = (ans + 1LL * dp[i - 1][j - 1] * C(n - i + m - j, n - i) % P) % P;
            }
        }
    }
    printf("%d\n", (ans + P) % P);
}
int main(){	
    init();
    scanf("%s%s", a + 1, b + 1);
    solve();
    return 0;
}