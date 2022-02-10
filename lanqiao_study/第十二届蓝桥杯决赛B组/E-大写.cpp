/**
  *@filename:E-大写
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-05 14:26
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

string s;
void solve(){
    for(auto &x : s){
        if(x >= 'a' && x <= 'z'){
            x -= 32;
        }
    }
    cout << s << endl;
}
int main(){
    cin >> s;
    solve();
    return 0;
}