#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5 + 10;
const int MOD = 1e9+7;
ll n, m, k, fac[10005];
ll qpow(ll x, ll y){
    ll res = 1ll;
    while(y){
        if(y&1) res = res*x%MOD;
        x = x*x%MOD;
        y >>= 1;
    }
    return res;
}
ll C(ll nn, ll mm){
    if(!mm) return 1ll;
    return fac[nn] * qpow(fac[nn-mm], MOD-2)%MOD * qpow(fac[mm], MOD-2)%MOD;
}
int main(){
    scanf("%lld%lld%lld", &n, &m, &k);
    ll res = 0;
    fac[1] = 1ll;
    for(ll i = 2;i <= 10000;i++){
        fac[i] = fac[i-1]*i%MOD;
    }
    ll ans = 0ll;
    for(ll i = 0;i <= min(n, k);i++){
        if(k-i > n*(n-1ll)) continue;
        ans += C(n, i) * C(n*(n-1ll), k-i)%MOD;
        printf("i = %lld, n = %lld, 1asn = %lld\n",i,n, ans);
    }
    m = (m-n)%MOD;
    for(int i = 1;i <= min(n, k);i++){
        if(k-i > n*(n-1ll)) continue;
        ans += C(n, i) * C(n*(n-1ll), k-i) %MOD * C(n, i)%MOD;
        printf("2ans = %lld\n", ans);
    }
    printf("%lld\n", ans);
    return 0;
}