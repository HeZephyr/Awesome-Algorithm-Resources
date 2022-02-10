/**
  *@filename:F
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-30 15:23
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

//点权转边权。
struct edge{
    int u,v,w;
    bool operator < (const edge &A){
        return w < A.w;
    }
}edges[N];
int n,m,tot;//顶点数、发电站数量。
int father[N];
ll ans;
int find(int x){
    int r = x;
    while(father[r] != r){
        r = father[r];
    }
    int i = x,j;
    while(father[i] != r){
        j = father[i];
        father[i] = r;
        i = j;
    }
    return r;
}
void solve(){
    //对电线排序。
    sort(edges + 1,edges + 1 + tot);
    for(int i = 1; i <= n + 1; ++ i){
        father[i] = i;
    }
    for(int i = 1; i <= tot; ++ i){
        int fu = find(edges[i].u),fv = find(edges[i].v);
        if(fu == fv)continue;//说明已经相连了。
        father[fu] = father[fv];
        ans += edges[i].w;
    }
    printf("%lld\n", ans);
}
int main(){
    scanf("%d%d", &n, &m);
    int idx,w;
    for(int i = 0; i < m; ++ i){
        scanf("%d%d", &idx, &w);
        edges[++tot] = {idx,n + 1,w};//将发电站看成结点n + 1
    }
    for(int i = 1; i <= n; ++ i){
        //输入电力线的成本。
        scanf("%d", &edges[++tot].w);
        edges[tot].u = i;
        if(i < n){
            edges[tot].v = i + 1;
        }
        else{
            edges[tot].v = 1;
        }
    }
    solve();
    return 0;
}