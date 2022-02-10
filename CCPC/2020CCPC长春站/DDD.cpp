#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3100 + 10;
const ll P = 1e9 + 7;
string s;
ll c, power[N], fac[N];
ll ksm(ll n, ll q){
    ll ans = 1;
    while(q){
        if(q & 1)ans = ans * n % P;
        n = n * n % P;
        q >>= 1;
    }
    return ans;
}
void init(){
    power[0] = fac[0] = 1;
    for(ll i = 1; i < N; ++ i){
        power[i] = power[i - 1] * c % P;
        fac[i] = fac[i - 1] * i % P;
    }
}
void solve(){
    int n = s.size();
    ll res = 0, cnt = 0;
    for(int i = 0; i < n; ++ i){
        if(s[i] == '1'){
            //处理n - i - 1;
            ll temp = n - i - 1;
            for(ll j = 0; j <= temp; ++ j){
                //C(temp, j) * power[j];
                //cout << temp << " " << j << " " << fac[temp] << " " << fac[j] << " " << power[cnt + j] << endl;
                res = (res + fac[temp] * ksm(fac[j], P - 2) % P * ksm(fac[temp - j], P - 2) % P * power[cnt + j] % P) % P;
                //cout << res << " " << endl;
            }
            ++ cnt;
        }
    }
    res = (res + power[cnt]) % P;
    cout << res << endl;
}
int main(){
    int n;
    cin >> s >> c;
    init();
    solve();
 }