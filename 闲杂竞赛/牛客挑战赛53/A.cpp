#include <bits/stdc++.h>

using ll = long long;
using namespace std;


int t;
ll x;
void solve(){
    ll k = 1LL * sqrt(2 * x);
    while((k + 1) * k < 2 * x){
        k ++;
    }
    ll n = (k + 1) * k / 2 - x;
    if(n == 1){
        cout << k + 1 << endl;
        return;
    }
    if(k > n){
        cout << k << endl;
        return;
    }
    cout << k + 1 << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> x;
        solve();
    }
    return 0;
}