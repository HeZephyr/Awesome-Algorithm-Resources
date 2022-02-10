#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e14;
const int N = 1e5 + 10;
ll t, n, m, fla;
ll a[N], b[N];
ll check(ll x){
    ll cnt = 0, tem;
    fla = 1e18;
    for(ll i = 1;i <= n;i++){
        if(b[i]>=x) continue;
        tem = ((x-b[i])+a[i]-1)/a[i];
        //fla = min(fla, b[i] + tem*a[i]);
        cnt += tem*2;
        b[i] += tem * a[i];
        if(i<n){
            b[i+1] += a[i+1]*tem;
        }
        if(i==n){
            b[i-1] += tem*a[i-1];
        }
    }
    for(int i = 1; i <= n; ++i){
        fla = min(fla, b[i]);
    }
    if(cnt<=m){
        //printf("fla = %lld\n", fla);
        return true;
    }
    else return false;
}
int main(){
    scanf("%lld", &t);
    while(t -- ){
        scanf("%lld%lld", &n, &m);
        ll ans = 1e18;
        for(ll i = 1;i <= n;i++){
            scanf("%lld", &a[i]);
            ans = min(ans, a[i]);
        }
        if(m<n){
            printf("0\n");
            continue;
        }
        m -= n;
        ll l = 0, r = 1e18;
        while(l <= r){
            for(int i = 1;i <= n;i++) b[i] = a[i];
            ll mid = l+r>>1;
            fla = 0;
            if(check(mid)){
                ans = max(ans, fla);
                l = mid+1;
            } else{
                r = mid-1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}