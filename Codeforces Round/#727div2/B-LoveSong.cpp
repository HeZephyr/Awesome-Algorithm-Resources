/**
  *@filename:B-LoveSong
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-26 13:16
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,q,l,r;
char s[N];
int pre[26][N];
void solve(){
    //cout << s + 1 << endl;
    for(int i = 1; i <= n; ++ i){
        for(int j = 0; j < 26; ++ j){
            pre[j][i] = pre[j][i - 1];
        }
        pre[s[i] - 'a'][i] ++;
    }
    while(q -- ){
        cin >> l >> r;
        ll cnt = 0;
        for(int i = 0; i < 26; ++ i){
            cnt += (pre[i][r] - pre[i][l - 1]) * (i + 1);
            //cout << pre[i][r] << endl;
        }
        cout << cnt << endl;
    }
}
int main(){
    cin >> n >> q >> s + 1;
    solve();
    return 0;
}