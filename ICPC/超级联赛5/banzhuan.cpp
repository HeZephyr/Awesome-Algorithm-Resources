/**
  *@filename:banzhuan
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-08-03 12:58
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const ll P = 1e9+7;

int t;
ll n;
ll qsm(ll n, ll q){
    ll ans = 1;
    while(q){
        if(q & 1)ans = ans % P * n % P;
        n = n % P * n % P;
        q >>= 1;
    }
    return ans;
}
void solve(){
    n %= P;
    //a is n * (n + 1) / 2, b is n * (n + 1) * (2 * n + 1) / 6
    ll a = n * (n + 1) % P * qsm(2,P - 2) % P, 
    b = n * (n + 1) % P * (2 * n + 1) % P * qsm(6,P - 2) % P;
    cout << (a * b % P + (a - 1) * (a - 1) % P + (b - 1) * (a - 1) % P) % P << endl;
    cout << a * b % P * (n % P) % P * (n % P) % P << endl;//max
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        solve();
    }
    return 0;
}