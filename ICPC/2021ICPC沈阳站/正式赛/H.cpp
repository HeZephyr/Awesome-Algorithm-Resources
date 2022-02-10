#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5 + 10;

int n, m;
struct edge{
    int u, to, next;
    ll w;
}e[N * 4];
int tot, head[N];
void add(int u, int v, int w){
    e[++ tot].next = head[u];
    e[tot].to = v;
    e[tot].u = u;
    e[tot].w = w;
    head[u] = tot;
}
int sz[N];
int vis[N];
void dfs(int u, int fu){
    sz[u] = 0;
    vis[u] = 1;
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to, w = e[i].w;
        if(fu == v || vis[v])continue;
        dfs(v, u);
        sz[u]++;
    }
    sz[fu] += sz[u];
}
vector<edge> g;
int dfn[N], low[N];
int idx, cnt;
void tarjan(int u, int fu){
    int v;
    low[u] = dfn[u] = ++ idx;
    for(int i = head[u]; i; i = e[i].next){
        v = e[i].to;
        if(v == fu)continue;
        if(!dfn[v]){
            tarjan(v, u);
            if(low[u] > low[v])low[u] = low[v];

            if(low[v] > dfn[u]){
                ++ cnt;
                g.push_back(e[i]);
            }
        }
        else if(low[u] > dfn[v]){
            low[u] = dfn[v];
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    ll sum = 0;
    int minx = INT_MAX;
    for(int i = 1, u, v, w; i <= m; ++ i){
        scanf("%d%d%lld", &u, &v, &w);
        sum += w;
        add(u, v, w), add(v, u, w);
        minx = min(minx, w);
    }
    if(m % 2 == 0){
        printf("%lld\n", sum);
        return 0;
    }
    dfs(1, 0);
    for(int i = 1; i <= n; ++ i){
        if(!dfn[i]){
            tarjan(i, 0);
        }
    }
    ll ans = INT_MAX;
    for(int i = 0; i < g.size(); ++i){
        int u = g[i].u, v = g[i].to;
        if(sz[u] < sz[v])swap(u, v);
        //cout << u << v << endl;
        //cout << sz[u] << sz[v] << endl;
        if(sz[v] % 2 == 0 && (m - sz[v] - 1) % 2 == 0)ans = min(ans, g[i].w);
    }
    if(g.size() == 0)ans = minx;
    printf("%lld\n", sum - ans);
    return 0;
}