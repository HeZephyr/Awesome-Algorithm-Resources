#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6+7;
const int MOD = 998244353;

ll a[N], b[N], fac[N], c[N], sum[N];
ll qpow(ll x, ll y){
    if(!x) return 1ll;
    ll res = 1ll;
    while(y){
        if(y&1) res = res*x%MOD;
        x = x*x%MOD;
        y>>=1ll;
    }
    return res;
}
int main(){
    ll n;
    scanf("%lld", &n);
    fac[1] = 1ll;
    for(ll i = 2;i <= 1e6;i++){
        fac[i] = fac[i-1]*i%MOD;
    }
    for(ll i = 1;i <= n;i++){
        scanf("%lld", &a[i]);
        b[a[i]]++;
    }
    sort(a+1, a+1+n);
    ll cnt = 0ll;
    ll ans = 1ll;
    for(ll i = n;i;i--){
        if(a[i]!=a[i-1]){
            c[++cnt] = b[a[i]];
            ans = ans*fac[c[cnt]]%MOD;
        }
    }
    for(ll i = cnt;i;i--){
        sum[i] = (sum[i+1] + c[i])%MOD;
    }
    for(ll i = 1;i < cnt;i++){
        ll tem = c[i]/2ll, cnt = 1ll;
        while(tem){
            ans = (ans*(sum[i+1]+cnt)%MOD);
            tem--;
            cnt++;
        }
        ans = ans * qpow(fac[c[i]/2ll], MOD-2)%MOD;
    }
    printf("%lld\n", ans);
    return 0;
}