#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn = 3e5 + 100;
const int maxm = 5e5 + 100;
const int mod = 998244353;
struct e_node{
    int to;
    int next;
    int f;
}e[maxm << 1];
int head[maxn], tot;
void add_e(int u, int v){
    e[++tot].to = v;
    e[tot].next = head[u];
    head[u] = tot;
}
ll dis[maxn];
int vis[maxn], vis2[maxn];
ll ans = 1;
ll sum = 0;
ll quick_pow(ll a, ll b){
    ll s = 1;
    while(b){
        if(b & 1)s *= a, s %= mod;
        a *= a; a %= mod;
        b >>= 1;
    }
    return s;
}
void dfs(int u, int father){
    vis[u] = 1;
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(v == father)continue;
        if(e[i].f)continue;
        if(vis[v]){
            ll len = abs(dis[v] - dis[u]) + 1;
            sum += len;
            ans = (ans * (quick_pow(2, len) - 1)) % mod;
            if(i % 2)e[i].f = e[i + 1].f = 1;
            else e[i].f = e[i - 1].f = 1;
        }
        else {
            dis[v] = dis[u] + 1;
            dfs(v, u);
        }
    }
}
int main(){
    int n;
    ll m;
    scanf("%d %lld", &n, &m);
    for(int i = 1; i <= m; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        add_e(u, v);
        add_e(v, u);
    }
    for(int i = 1; i <= n; ++i){
        if(vis[i])continue;
        dfs(i, 0);
    }
    
    ans = ans * quick_pow(2, m - sum) % mod;
    printf("%lld", ans % mod);
}