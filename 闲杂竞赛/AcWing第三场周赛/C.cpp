/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-12 18:58
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,m,r,c;
void solve(){
    ll ans = 0;
    cout << max(n - r + m - c,max(max(r - 1 + c - 1, n - r + c - 1),r - 1 + m - c)) << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> m >> r >> c;
        solve();
    }
    return 0;
}