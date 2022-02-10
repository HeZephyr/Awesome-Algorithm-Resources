#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5 + 10;

int n, m;
struct edge{
    int u, v, w, next, id;
}edges[N * 4];
int tot, head[N];
int a[N];
void add(int u, int v, int w){
    edges[++ tot].v = v;
    edges[tot].u = u;
    edges[tot].next = head[u];
    edges[tot].w = w;
    head[u] = tot;
}
int cnt[2];
void dfs(int u, int fu, int x, int bit){
    a[u] = x;
    cnt[x] ++;
    for(int i = head[u], v, w; i; i = edges[i].next){
        v = edges[i].v, w = edges[i].w;
        if(v == fu || a[v] != -1)continue;
        dfs(v, u, ((w >> bit) & 1) ^ x, bit);
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1, u, v, w; i <= m; ++ i){
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w), add(v, u, w);
    }
    ll res = 0;
    bool flag = true;
    for(int i = 30; i >= 0; -- i){
        for(int j = 1; j <= n; ++ j)a[j] = -1;
        for(int u = 1; u <= n; ++ u){
            cnt[0] = cnt[1] = 0;
            if(a[u] == -1){
                dfs(u, 0, 0, i);
            }
            if(cnt[0] < cnt[1])swap(cnt[0], cnt[1]);
            res += 1LL * cnt[1] * (1LL << i);
        }
        for(int j = 1; j <= tot; ++ j){
            if(a[edges[j].u] ^ a[edges[j].v] != ((edges[j].w >> i) & 1)){
                flag = false;
                break;
            }
        }
        if(!flag)break;
    }
    if(!flag)puts("-1");
    else{
        printf("%lld\n", res);
    }
    return 0;
}