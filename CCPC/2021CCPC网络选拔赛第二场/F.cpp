#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 998244353;

int t;
int dp[N][13];//dp[i][j]表示前i个已经配对到匹配字符串中的第j个字符的组合数。
int cnt[N];
char s[N];
int ksm(int n, int q){
    int ans = 1;
    while(q){
        if(q & 1)ans = 1LL * ans * n % P;
        q >>= 1;
        n = 1LL * n * n % P;
    }
    return ans;
}
void solve(){
    char temp[13] = " nunhehheh";
    int len1 = strlen(s + 1),len2 = 9;
    for(int j = 1; j <= len2; ++ j){
        dp[0][j] = 0;
    }
    memset(cnt, 0, sizeof(cnt));
    for(int j = len1; j >= 1; -- j){
        if(s[j] == 'a'){
            cnt[j] = cnt[j + 1] + 1;
        }
        else{
            cnt[j] = cnt[j + 1];
        }
    }
    for(int i = 0; i <= len1; ++ i){
        dp[i][0] = 1;
    }
    for(int i = 1; i <= len1; ++ i){
        for(int j = 1; j <= len2; ++ j){
            if(s[i] == temp[j]){
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % P;
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    ll res = 0;
    for(int i = 1; i <= len1; ++ i){
        if(s[i] == 'a'){
            res = (res + 1LL * dp[i][len2] * ksm(2, cnt[i + 1]) % P) % P;
        }
    }
    cout << res << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> s + 1;
        solve();
    }
    return 0;
}