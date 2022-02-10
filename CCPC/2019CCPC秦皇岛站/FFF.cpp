#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int N = 3e5+7;
const int M = 5e5+7;
const int mod = 998244353;
vector<ll> g[N];
int vis[N];
ll sm, a[N], sum;
ll qpow(ll x, ll y){
    ll res = 1ll;
    while(y){
        if(y&1) res = res*x%mod;
        x = x*x%mod;
        y >>= 1ll;
    }
    return res;
}
void dfs(ll u, ll from, ll cnt){
    if(vis[u]){
        sum = sum*(qpow(2ll, cnt-a[u]) - 1ll) % mod;
        sm -= cnt-a[u];
        return;
    }
    a[u] = cnt;
    vis[u] = 1;
    for(auto it : g[u]){
        if(it==from || vis[it]==-1) continue;
        dfs(it, u, cnt+1); 
    }
    vis[u] = -1;
}
int main(){
    ll n, m, u, v;
    scanf("%lld%lld",&n, &m);
    sm = m, sum = 1ll;
    for(int i = 1;i <= m;i++){
        scanf("%lld%lld", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1;i <= n;i++){
        if(vis[i]==0)
            dfs(i, 0, 1);
    }   
    sum = sum*qpow(2ll, sm)%mod;
    printf("%lld\n", sum);
    return 0;
}