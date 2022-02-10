#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 1024523, N = 1e3 + 10;
int dp[2][N][N];

void solve() {
    int n, m; cin >> n >> m;
    string s, t;
    cin >> s >> t;
    s = "@" + s, t = "@" + t;
    dp[0][0][0] = 1;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            for (int k = 0; k <= min(n, i + j); ++k) {
                int l = i + j - k;
                if (!i and !j and !k) {
                    dp[i & 1][j][k] = 1;
                    continue;
                }
                dp[i & 1][j][k] = 0;
                if (i and k and s[i] == s[k]) {
                    dp[i & 1][j][k] += dp[(i + 1) & 1][j][k - 1];
                    dp[i & 1][j][k] %= P;
                }
                if (i and l and s[i] == t[l]) {
                    dp[i & 1][j][k] += dp[(i + 1) & 1][j][k];
                    dp[i & 1][j][k] %= P;
                }
                if (j and k and t[j] == s[k]) {
                    dp[i & 1][j][k] += dp[i & 1][j - 1][k - 1] ;
                    dp[i & 1][j][k] %= P;
                }
                if (j and l and t[j] == t[l]) {
                    dp[i & 1][j][k] += dp[i & 1][j - 1][k];
                    dp[i & 1][j][k] %= P;
                }
            }
    cout << dp[n & 1][m][n] << "\n";
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}