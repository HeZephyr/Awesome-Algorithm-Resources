#include <bits/stdc++.h>

using namespace std;

const int N = 52, mod = 1e9 + 7;

int n;
string s, t;
int ne[N];
int f[N][N];
//f[i][j]表示串S前i位为与串T前j位匹配成功，第i位匹配到子串中位置位j时(S[i - j + 1 ~ i] == T[1 ~ j])的方案数

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> t;
    s = ' ' + t;
    int m = s.length() - 1;

    for (int i = 2, j = 0; i <= m; ++ i) {
        while (j && s[i] != s[j + 1]) j = ne[j];
        if (s[i] == s[j + 1]) ++j;
        ne[i] = j;
    }

    f[0][0] = 1;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            for (char k = 'a'; k <= 'z'; ++ k) { //假定S[i + 1]位为k，与T[j + 1]位进行匹配判断
                int jj = j;
                while (jj && k != s[jj + 1]) jj = ne[jj];
                if (k == s[jj + 1]) ++jj;
                //f[i + 1][jj]代表串S前i+1位与串前jj位匹配成功(S[i+1-jj+1~i+1] == T[1~jj])方案数
                if (jj < m) 
                    f[i + 1][jj] = (f[i + 1][jj] + f[i][j]) % mod;
                //f[i][j]可以通过i+1赋值为k到达f[i+1][jj]点（新增路径）
                //注:可能存在重边,因为j不同但ne[j]是相同的,并且k是相同的,所以此时
                //f[i][j1]和f[i][j2]跳到的位置是一样的(k相同,ne[j1]=ne[j2])
            }
        }
    }

    int res = 0;
    for (int i = 0; i < m; ++ i) res = (res + f[n][i]) % mod;
    cout << res << "\n";

    return 0;
}