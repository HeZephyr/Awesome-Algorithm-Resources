/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-26 16:07
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
string s;
void solve(){
    int ans = 0;
    n = s.size();
    for(int i = 0; i < n ; ++ i){
        if(s[i] == '.')continue;
        if(i + 2 < n && s[i] == s[i + 2]){
            ans ++;
            s[i + 2] = '.';
        }
        if(i + 1 < n && s[i] == s[i + 1]){
            ans ++;
            s[i + 1] = '.';
        }
    }
    cout << ans << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> s;
        solve();
    }
    return 0;
}