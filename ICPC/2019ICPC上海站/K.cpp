#include<bits/stdc++.h>

using namespace std;

const int N = 20;
int t, n, m;
struct edge{
    int to, next;
}edges[N * N];
int head[N], tot;
void add(int u, int v){
    edges[++ tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
int cnt, vis[N];
map<pair<int, int>, int> p;
void dfs(int u, int fu, int cnt = 0){
    for(int i = head[u], v; i; i = edges[i].next){
        v = edges[i].to;
        if(v == fu || p[{u, v}] || p[{v, u}])continue;

    }
}
int main(){
    cin >> t;
    for(int k = 1; k <= t; ++ k){
        cin >> n >> m;
        cnt = m;         
        p.clear();
        for(int i = 1; i <= n; ++ i)vis[i] = 0;
        for(int i = 1, u, v; i <= m; ++ i){
            scanf("%d%d", &u, &v);
            add(u, v), add(v, u);
        }
        for(int i = 1; i <= n; ++ i){
            dfs(i, 0);
        }
        printf("Case #%d: %d\n", k, cnt);
    }
    return 0;
}