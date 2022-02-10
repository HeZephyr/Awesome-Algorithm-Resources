/**
  *@filename:C_Strange_Function
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-03 22:38
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
ll n;
void solve(){
    ll ans = 0,temp = 1;
    for(ll i = 1, j = 1; temp <= n; ++ i, ++ j ){
        ans += n / temp;
        ans %= P;
        ll res = n / i - j;
        ll gcd = __gcd(i,temp);
        if(temp > (res + j) * gcd)break;
        temp = temp * i / __gcd(i,temp);
    }
    cout << ans << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        solve();
    }
    return 0;
}