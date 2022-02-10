/**
  *@filename:P2303
  *@author: pursuit
  *@created: 2021-09-18 09:25
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

ll n;
ll eular(ll n){
    ll res = n;
    for(ll i = 2; i * i <= n; ++ i){
        if(n % i == 0){
            res -= res / i;
            while(n % i == 0){
                n /= i;
            }
        }
    }
    if(n > 1){
        res -= res / n;
    }
    return res;
}
void solve(){
    ll x = sqrt(n);
    ll res = 0;
    for(ll i = 1; i <= x; ++ i){
        if(n % i == 0){
            res += i * eular(n / i);
            if(i * i != n)res += n / i * eular(i);
        }
    }
    cout << res << endl;
}
int main(){	
    cin >> n;
    solve();
    return 0;
}