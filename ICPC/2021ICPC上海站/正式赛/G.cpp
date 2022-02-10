#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn = 1e5 + 100;
const int mod = 998244353;
struct e_node{
    int to;
    int next;
}e[maxn << 1];
int head[maxn], tot;
void add_e(int u, int v){
    e[++tot].to = v;
    e[tot].next = head[u];
    head[u] = tot;
}
int vis[maxn];
int du[maxn];
int dep[maxn];
struct a_node{
    int x;
    bool operator < (const a_node &A) const{
        return dep[x] > dep[A.x];
    }
};
ll jc[maxn], pow_2[maxn];
int n;
void pre(){
    jc[0] = 1;pow_2[0] = 1;
    for(int i = 1; i <= maxn - 100; ++i){
        jc[i] = jc[i - 1] * i % mod;
        pow_2[i] = pow_2[i - 1] * 2ll % mod;
    }
}
ll quick_pow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1)ans *= a, ans %= mod;
        a *= a;a %= mod;
        b >>= 1ll;
    }
    return ans;
}
ll sz[maxn];
ll ans = 1;
void dfs(int u, int father){
    dep[u] = dep[father] + 1;
    sz[u] = 1;
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(v == father)continue;
        dfs(v, u);
        if(sz[v] == 2)continue;
        sz[u] += sz[v];
    }
    if(sz[u] % 2 == 0){
        ans = (ans * jc[sz[u]] % mod *  quick_pow(pow_2[sz[u]/2]*jc[sz[u]/2]%mod, mod - 2) % mod) % mod;
        sz[u] = 0;
    }
    else if(sz[u] > 1){
        sz[u]--;
        ans = (ans * jc[sz[u]] % mod *  quick_pow(pow_2[sz[u]/2]*jc[sz[u]/2]%mod, mod - 2) % mod) % mod;
        sz[u] = 1;
    }
}
int main(){
    pre();
    scanf("%d", &n);
    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        add_e(v, u);
        add_e(u, v);
        du[u]++;
        du[v]++;
    }
    int root = 0;
    priority_queue<a_node> Q;
    for(int i = 1; i <= n; ++i){
        //if(du[i] % 2 == 0)Q.push(a_node{i});
        if(du[i] == 1)root = i;
    }
    //cout << root << endl;
    dfs(1, 0);
    printf("%lld", ans);
    return 0;
}