/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-16 14:39
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

ll n,b;
map<ll,ll> p;//存储b的质因子及其数量。
ll cal(ll n, ll x){
    ll res = 0;
    while(n){
        res += n / x;
        n /= x;
    }
    return res;
}
void solve(){
    ll temp = sqrt(b);
    for(ll i = 2; i <= temp; ++ i){
        if(b % i == 0){
            ll cnt = 0;
            while(b % i == 0){
                cnt ++;
                b /= i;
            }
            p[i] = cnt;  
        }
    }
    if(b > 1){
        p[b] ++;
    }
    ll ans = 1e18;
    for(auto &x : p){
        //cout << x.first << endl;
        ans = min(ans,cal(n,x.first) / x.second);
    }
    cout << ans << endl;
}
int main(){	
    cin >> n >> b;
    solve();
    return 0;
}