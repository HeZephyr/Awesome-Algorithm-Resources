/**
  *@filename:D_Say_No_to_Palindromes
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-31 00:22
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int n,m;
int pre[N][26];
char s[N];
void solve(){
    for(int i = 1; i <= n; ++ i){
        for(int j = 0; j < 26; ++ j){
            pre[i][j] = pre[i - 1][j];
        }
        pre[i][s[i] - 'a'] ++;
    }
    int l,r;
    for(int i = 0; i < m; ++ i){
        cin >> l >> r;
        int ans = 0;
        for(int j = 0; j < 26; ++ j){
            ans += (pre[r][j] - pre[l - 1][j]) / 2;
        }
        cout << ans << endl;
    }
}
int main(){
    cin >> n >> m >> s + 1;
    solve();
    return 0;
}