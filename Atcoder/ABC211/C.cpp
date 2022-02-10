/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-24 20:06
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int dp[N][10];//dp[i][j]表示前i个已经配对到匹配字符串中的第j个字符的组合数。
char s[N];
void solve(){
    char temp[10] = " chokudai";
    int len1 = strlen(s + 1),len2 = strlen(temp + 1);
    for(int j = 1; j <= len2; ++ j){
        dp[0][j] = 0;
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
    cout << dp[len1][len2] << endl;
}
int main(){
    cin >> s + 1;
    solve();
    return 0;
}