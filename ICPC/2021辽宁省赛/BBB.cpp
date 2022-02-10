#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 500 + 10;
const ll INF = 1e18 + 10;
int n, m;
ll a[N], res[N][N];
struct node{
    int u, v, w;
    bool operator < (const node &A){
        return w < A.w;
    }
}b[N], c[N * N];
struct edge{
    int to, next;
    ll w;
}edges[N * N];
int tot, head[N];
int father[N];
bool flag[N];
void add(int u, int v, int w){
    edges[++ tot].to = v;
    edges[tot].next = head[u];
    edges[tot].w = w;
    head[u] = tot;
}
int find(int x){
    int r = x;
    while(r != father[r])r = father[r];
    int i = x, j;
    while(father[i] != r){
        j = father[i];
        father[i] = r;
        i = j;
    }
    return r;
}
void dfs(int rt, int u, int fu, ll mx1, ll mx2){
    res[rt][u] = res[u][rt] = min(res[rt][u], mx1 * mx2);
    for(int i = head[u], v; i; i = edges[i].next){
        v = edges[i].to;
        //printf("%d->%d\n", u, v);
        if(v == fu)continue;
        dfs(rt, v, u, max(mx1, a[v]), max(mx2, edges[i].w));
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
        b[i].u = i, b[i].w = a[i];
    }
    fill(res[0], res[0] + N * N, INF);
    for(int i = 1, u, v, w; i <= m; ++ i){
        scanf("%d%d%d", &c[i].u, &c[i].v, &c[i].w);
    }
    sort(b + 1, b + 1 + n);
    sort(c + 1, c + 1 + m);
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j)father[j] = j;
        for(int j = 1; j <= n; ++ j){
            head[j] = 0;
            flag[j] = 0;
        }
        for(int j = 1; j <= i; ++ j){
            flag[b[j].u] = true;
        }
        tot = 0;
        for(int j = 1; j <= m; ++ j){
            if(!flag[c[j].u] || !flag[c[j].v])continue;
            int u = find(c[j].u), v = find(c[j].v);
            if(u != v){
                father[u] = v;
                add(c[j].u, c[j].v, c[j].w),add(c[j].v, c[j].u, c[j].w);
            }
        }
        for(int j = 1; j <= n; ++ j){
            if(flag[j]){
                dfs(j, j, -1, a[j], 0);
            }
        }
    }
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            if(res[i][j] >= INF)printf("-1 ");
            else printf("%lld ", res[i][j]);
        }
        puts("");
    }
    return 0;
}