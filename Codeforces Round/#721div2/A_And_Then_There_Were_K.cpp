/**
  *@filename:A_And_Then_There_Were_K
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-20 22:35
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
void solve(){
    int cnt = 1;
    while(n > 1){
        cnt <<= 1;
        n >>= 1;
    }
    cout << cnt - 1 << endl;
}
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        solve();
    }
    return 0;
}