#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6 + 10;
int t, n, tot, m;
struct edge{
    int u, v;
}edges[N];
int father[N], res[N];
int find(int x){
    int r = x;
    while(r != father[r]){
        r = father[r];
    }
    int i = x, j;
    while(father[i] != r){
        j = father[i];
        father[i] = r;
        i = j;
    }
    return r;
}
int solve(){
    for(int i = 1; i <= m; ++ i){
        int fu = find(edges[i].u), fv = find(edges[i].v);
        if(fu != fv){
            res[fv] = res[fv] + res[father[fu]] + 1;
            res[father[fu]] = 0;
            father[fu] = fv;
        }
        else{
            ++ res[fv];
        }
    }
    for(int i = 1; i <= n; ++ i){
        int x = find(i);
        -- res[x];
    }
    int maxx = 0;
    for(int i = 1; i <= n; ++ i){
        if(res[i] > 0)maxx += res[i];
    }
    return maxx;
}
int main(){
    scanf("%d", &t);
    for(int k = 1; k <= t; ++ k){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; ++ i){
            scanf("%d%d", &edges[i].u, &edges[i].v);
        }
        for(int i = 1; i <= n; ++ i){
            father[i] = i;
            res[i] = 0;
        }
        printf("Case #%d: %d\n", k, solve());
    }
    return 0;
}