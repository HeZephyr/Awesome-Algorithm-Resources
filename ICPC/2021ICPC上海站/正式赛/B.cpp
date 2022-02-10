#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5+7;
const int mod = 998244353;
ll a[N], fac[N], pr[N];
bool vis[N];
ll qpow(ll x, ll y){
    ll res = 1ll;
    while(y){
        if(y&1) res = res*x%mod;
        x = x*x%mod;
        y >>= 1ll;
    }
    return res;
}

ll C(ll n, ll m){
    if(n==0 || m==0) return 1ll;
    return fac[n]*qpow(fac[n-m], mod-2)%mod * qpow(fac[m], mod-2)%mod;
}

int main(){
    ll n;
    scanf("%lld", &n);
    fac[0] = pr[0] = 1ll;
    for(ll i = 1;i <= 1e5;i++){
        fac[i] = fac[i-1]*i%mod;
        pr[i] = pr[i-1]*2ll%mod;
    }
    for(ll i = 1;i <= n;i++){
        scanf("%lld", &a[i]);
    }
    ll cnt = 0;
    for(ll i = 1;i <= n;i++){
        if(vis[i] || i==a[i]) continue;
        if(i == a[a[i]]){
            cnt++;
            vis[i] = vis[a[i]] = 1;
        }
    }
    ll ans = fac[n];
    for(ll i = 1;i <= cnt;i++){
        if(i&1) ans = (ans - C(cnt, i) * fac[n-2*i+1ll]%mod * pr[i] % mod * fac[i]%mod + mod) % mod;
        else ans = (ans + C(cnt, i) * fac[n-2*i+1ll]%mod * pr[i]%mod * fac[i]%mod + mod) % mod;
        //printf("ans = %lld, cnt = %lld, i = %lld\n", ans,cnt, i);
    }
    printf("%lld\n", ans);
    return 0;
}