#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll P = 998244353;

const int N = 1e5+7;
int n, m, a[N];
ll ksm(ll n, ll q){
    ll ans = 1;
    while(q){
        if(q & 1)ans = ans * n % P;
        n = n * n % P;
        q >>= 1;
    }
    return ans;
}
ll fac[N], inv[N];
void init(){
    fac[0] = fac[1] = 1;
    for(int i = 2; i <= m; ++ i){
        fac[i] = fac[i - 1] * i % P;
    }
    for(int i = 0; i <= m; ++ i){
        inv[i] = ksm(i, P - 2) % P;
    }
}
int main(){
    scanf("%d%d", &n, &m);
    int maxx = 0;
    init();
    for(int i = 1, x;i <= n;i++){
        scanf("%d", &x);
        maxx = max(maxx, x);
        ++ a[x];
    }
    vector<pll> ans;
    for(int i = 0; i <= 1e5; ++ i){
        if(a[i]){
            ans.push_back({i, a[i]});
            //cout << i << " " << a[i] << endl;
        }
    }
    ll res = 1;
    for(ll k = 1; k <= m; ++ k){
        if(k < maxx){
            printf("0");
        }
        else if(k == maxx){
            for(auto [w, cnt] : ans){
                res = res * ksm(fac[k] % P * ksm(fac[k - w], P - 2) % P * ksm(fac[w], P - 2) % P, cnt) % P;
            }
            printf("%lld", res);  
        }
        else{
            res = res * ksm(k, n) % P;
            for(auto [w, cnt] : ans){
                res = res * ksm(inv[k - w], cnt) % P;
            }
            printf("%lld", res);
        }
        if(k != m)puts("");
    }
    return 0;
}