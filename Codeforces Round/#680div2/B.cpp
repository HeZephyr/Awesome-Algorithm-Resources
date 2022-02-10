/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-08 08:10
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,a,b,c,d;
void solve(){
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> a >> b >> c >> d;
        cout << max(a + b,c + d) << endl;
        solve();
    }
    return 0;
}