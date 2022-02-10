/**
  *@filename:Great_Cow_Gathering_G
  *@author: pursuit
  *@created: 2021-11-01 21:39
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
const ll N = 1e6 + 10;
const ll P = 1e9 + 7;
const ll INF = 0x3f3f3f3f;

ll n, a[N], sum[N], dep[N];
ll res[N];
struct node{
    ll to, next, w;
}edges[N << 1];
ll head[N], tot;
void add(ll u, ll v, ll w){
    edges[++ tot].next = head[u];
    edges[tot].w = w;
    edges[tot].to = v;
    head[u] = tot;
}
void bfs(){
    queue<ll> q;
    q.push(1);
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(ll i = head[u], v; i; i = edges[i].next){
             v = edges[i].to;
             if(v != 1 && !dep[v]){
                dep[v] = dep[u] + edges[i].w;
                q.push(v);
             }
        }
    }
}
void dfs1(ll u, ll fu){
    sum[u] = a[u];
    for(ll i = head[u], v; i; i = edges[i].next){
        v = edges[i].to;
        if(v == fu)continue;
        res[v] = res[u] + sum[1] * edges[i].w - 2 * edges[i].w * sum[v];
        //cout << u << "->" << v << " " << res[u] << " " << res[v] << endl;
        dfs1(v, u);
        sum[u] += sum[v];
    }
}
void dfs2(ll u, ll fu){
    for(ll i = head[u], v; i; i = edges[i].next){
        v = edges[i].to;
        if(v == fu)continue;
        res[v] = res[u] + sum[1] * edges[i].w - 2 * edges[i].w * sum[v];
        //cout << u << "->" << v << " " << res[u] << " " << res[v] << endl;
        dfs2(v, u);
    }
}
void solve(){
    bfs();
    dfs1(1, 0);
    for(ll i = 1; i <= n; ++ i){
        //cout << a[i] << " " << dep[i] << endl;
        res[1] += a[i] * dep[i];
    }
    dfs2(1, 0);
    ll minn = res[1];
    for(ll i = 2; i <= n; ++ i){
        minn = min(minn, res[i]);
    }
    printf("%lld\n", minn);
}
int main(){	
    scanf("%d", &n);
    for(ll i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for(ll i = 1, u, v, w; i < n; ++ i){
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w), add(v, u, w);
    }
    solve();
    return 0;
}