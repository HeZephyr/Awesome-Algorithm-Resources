/**
  *@filename:签到
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-08-01 14:00
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P =  998244353;

int t;
ll a,b,k;
ll qsm(ll n, ll q){
    ll ans = 1;
    while(q){
        if(q & 1)ans = ans * n % P;
        n = n * n % P;
        q >>= 1;
    }
    return ans;
}
void solve(){
    ll temp = qsm(2,k / 2);
    a = 1LL * temp % P * a % P;
    b = 1LL * temp % P * b % P;
    if(k & 1){
        int temp1 = a,temp2 = b;
        a = temp1 + temp2;
        b = temp1 - temp2;
        a = (a + P) % P;
        b = (b + P) % P;
    } 
    cout << a << " " << b << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> a >> b >> k;
        solve();
    }
    return 0;
}