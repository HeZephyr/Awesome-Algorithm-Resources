/**
  *@filename:F-最优包含
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-04 20:08
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000 + 5;
const int P = 1e9+7;

char s[N],t[N];//使得s包含t。
int dp[N][N];//dp[i][j]表示需要至少修改s[1..i]中的多少字符才能包含t[1...j]。
//我们知道对于dp[i][j]，它有两种方式转移过来，一种是dp[i - 1][j],还有一种是dp[i - 1][j - 1]。
//对于第二种，我们需要考虑s[i] 和 s[j]是否相等。则可知。
void solve(){
    int len1 = strlen(s + 1),len2 = strlen(t + 1);
    for(int j = 1; j <= len2; ++ j)dp[0][j] = 0x3f3f3f3f;
    for(int i = 1; i <= len1; ++ i){
        for(int j = 1; j <= len2; ++ j){
            dp[i][j] = min(dp[i - 1][j],dp[i - 1][j - 1] + (s[i] != t[j]));
        }
    }
    printf("%d\n",dp[len1][len2]);
}
int main(){
    cin >> s + 1 >> t + 1;
    solve();
    return 0;
}