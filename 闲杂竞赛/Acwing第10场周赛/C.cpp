/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-31 19:06
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

string s;
ll cnt[26],f[26][26];
void solve(){
    ll ans = 0;
    for(int i = 0; i < s.size(); ++ i){
        int t = s[i] - 'a';
        for(int j = 0; j < 26; ++ j){
            f[j][t] += cnt[j];
            ans = max(ans,f[j][t]);
        }
        cnt[t] ++;
        ans = max(ans,cnt[t]);
    }
    cout << ans << endl;
}
int main(){
    cin >> s;
    solve();
    return 0;
}