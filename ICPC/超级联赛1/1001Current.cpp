/**
  *@filename:1001Current
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-21 10:42
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
ll quick_pow(ll x,ll b){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = ans * x;
        }
        x *= x;
        b >>= 1;
    }
    return ans;
}
ll n;
int cal(ll m){
    int temp = -1;
    for(ll j = 50; j >= 0; -- j){
        if(m >> j){
            temp = j;
            break;
        }
    }
    return temp;
}
void solve(){
    if(n <= 2){
        cout << "0" << endl;
        return;
    }
    ll m = (n - 1) / 2;
    int k = cal(m);
    cout << quick_pow(2,k + 1) - 1 << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        solve();
    }
    return 0;
}