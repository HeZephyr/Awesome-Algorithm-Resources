#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

typedef long long ll;

int n,m;
struct node{
    int u;
    ll w;
    bool operator < (const node &A){
        return w < A.w;
    }
}nodes[N];
struct edge{
    int u,v;
    ll w;
    bool operator < (const edge &A){
        return w < A.w;
    }
}edges[N << 2];
int tot,father[N];
int find(int x){
    int r = x;
    while(r != father[r])r = father[r];
    int i = x,j;
    while(father[i] != r){
        j = father[i];
        father[i] = r;
        i = j;
    }
    return r;
}
void solve(){
    sort(nodes + 1, nodes + 1 + n);
    for(int i = 2; i <= n; ++ i){
        //如果不适用魔法，而是直接连接的话必然是选择权值较小的，则以最小的与其他n-1个点相连即可。
        edges[++ tot].u = nodes[1].u;
        edges[tot].v = nodes[i].u;
        edges[tot].w = nodes[i].w + nodes[1].w;
    }
    sort(edges + 1, edges + 1 + tot);
    for(int i = 1; i <= n; ++ i)father[i] = i;
    ll ans = 0;
    for(int i = 1; i <= tot; ++ i){
        int fu = find(edges[i].u), fv = find(edges[i].v);
        if(n == 1)break;//当集合只剩一下即连通。
        if(fu != fv){
            father[fu] = fv;
            ans += edges[i].w;
            n --;
        }
    }
    printf("%lld\n", ans);
}
int main(){
    scanf("%d%d", &n ,&m);
    for(int i = 1; i <= n; ++ i){
        scanf("%lld", &nodes[i].w);
        nodes[i].u = i;
    }
    for(int i = 1; i <= m; ++ i){
        tot ++;
        scanf("%d%d%lld", &edges[tot].u, &edges[tot].v, &edges[tot].w);
    }
    solve();
    return 0;
}