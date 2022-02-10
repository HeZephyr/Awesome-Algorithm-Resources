#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int INF = 1e9;
struct edge{
    int u, v, next, w;
    bool cut;
}edges[N * N];
int idx;
int tot, head[N];
int n, m;
int dfn[N], low[N];
void add(int u, int v, int w){
    edges[++ tot].next = head[u];
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].cut = false;
    head[u] = tot;
}
void tarjan(int u, int fu){
    int v;
    low[u] = dfn[u] = ++ idx;
    for(int i = head[u]; i; i = edges[i].next){
        v = edges[i].v;
        //puts("hello");
        if(v == fu)continue;
        //cout << u << "->" << v << endl;
        if(!dfn[v]){
            tarjan(v, u);
            if(low[u] > low[v])low[u] = low[v];
            if(low[v] > dfn[u]){
                edges[i].cut = true;
            }
        }
        else{
            if(low[u] > dfn[v]){
                low[u] = dfn[v];
            }
        }
    }
}
int main(){
    while(scanf("%d%d", &n, &m) != EOF && (n || m)){
        idx = tot = 0;
        memset(head, 0, sizeof(head));
        memset(dfn, 0, sizeof(dfn));
        for(int i = 1, u, v, w; i <= m; ++ i){
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w), add(v, u, w);
        }
        for(int i = 1; i <= n; ++ i){
            if(!dfn[i]){
                tarjan(i, i);
            }
        }
        int minn = INF;
        for(int u = 1; u <= n; ++ u){
            for(int i = head[u]; i; i = edges[i].next){
                if(edges[i].cut){
                    minn = min(minn, edges[i].w);
                }
            }
        }
        if(minn == INF)puts("-1");
        else printf("%d\n", minn);
    }
    return 0;
}