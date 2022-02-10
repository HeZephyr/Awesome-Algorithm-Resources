#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int INF = 1e9;
int idx;
int tot, head[N];
int n, m;
struct node{
    int w, cnt;
    node(int _w = INF, int _cnt = 0){
        w = _w, cnt = _cnt;
    }
};
bool cut[N][N];
node g[N][N];
int father[N];
int find(int x){
    int r = x;
    while(father[r] != r)r = father[r];
    int i = x, j;
    while(father[i] != r){
        j = father[i];
        father[i] = r;
        i = j;
    }
    return r;
}
int dfn[N], low[N];
void tarjan(int u, int fu){
    int v;
    low[u] = dfn[u] = ++ idx;
    for(v = 1; v <= n; ++ v){
        if(g[u][v].w != INF){
            //puts("hello");
            if(v == fu)continue;
            //cout << u << "->" << v << endl;
            if(!dfn[v]){
                tarjan(v, u);
                if(low[u] > low[v])low[u] = low[v];
                if(low[v] > dfn[u]){
                    cut[u][v] = true;
                }
            }
            else{
                if(low[u] > dfn[v]){
                    low[u] = dfn[v];
                }
            }
        }
    }
}
int main(){
    while(scanf("%d%d", &n, &m) != EOF && (n || m)){
        idx = 0;
        for(int i = 1; i <= n; ++ i){
            dfn[i] = 0;
            father[i] = i;
            for(int j = 1; j <= n; ++ j){
                g[i][j].w = INF, g[i][j].cnt = 0;
                cut[i][j] = false;
            }
        }
        int cnt = n;
        for(int i = 1, u, v, w; i <= m; ++ i){
            scanf("%d%d%d", &u, &v, &w);
            int fu = find(u), fv = find(v);
            if(fu != fv){
                father[fu] = fv;
                -- cnt;
            }
            g[u][v].w = min(w, g[u][v].w);
            g[u][v].cnt ++;
            g[v][u].w = min(w, g[v][u].w);
            g[v][u].cnt ++;
        }
        if(cnt != 1){
            puts("0");
            continue;
        }
        for(int i = 1; i <= n; ++ i){
            if(!dfn[i]){
                tarjan(i, i);
            }
        }
        int minn = INF;
        for(int u = 1; u <= n; ++ u){
            for(int v = 1; v <= n; ++ v){
                if(cut[u][v] && g[u][v].w != INF && g[u][v].cnt == 1){
                    minn = min(g[u][v].w, minn);
                }
            }
        }
        if(minn == INF)puts("-1");
        else printf("%d\n", max(minn, 1));
    }
    return 0;
}