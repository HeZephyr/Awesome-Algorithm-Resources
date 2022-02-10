#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 1e5+7;
ll ans[N];
int main(){
    ll n, k, s, sum = 0;
    scanf("%lld%lld%lld", &n, &k, &s);
    if(k==1){
        if(n&1){
            ll m = s/(n-1ll);

        } else {
            ll m = s/(n/2);
            for(ll i = 1;i <= n;i++){
                if(i&1) printf("%lld\n", m/2);
                else printf("%lld\n", )
            }
        }
    }
    sum = (n/(k+1ll)) * (1ll+k)*k/2ll;
    ll m = n%(k+1ll);
    for(ll i = 0ll;i < m;i++){
        sum += i;
    }
    //printf("sum = %lld\n", sum);
    if(s<sum){
        printf("-1\n");
        return 0;
    }
    bool fla = 1;
    ll x = 0;
    //printf("sum = %lld\n", sum);
    for(ll i = 0;i < k && sum<=s;i++){
        if(i) sum += n;
        if((s-sum)%(k+1ll)==0){
            fla = 0;
            x = i;
            break;
        }
    }
    if(fla){
        printf("-1\n");
        return 0;
    }
    ll y = (s-sum)/(k+1ll);
    m = y/n;
    ll mod = y%n;
    for(ll i = 0;i < n;i++){
        ans[i] = i%(k+1ll) + x + m*(k+1ll);
        if(i<mod) ans[i] += k+1ll;
    }
    for(ll i = 0;i < n;i++){
        printf("%lld ", ans[i]);
    }
    return 0;
}
