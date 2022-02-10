/**
  *@filename:1009
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-21 11:06
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 500000 + 5;
const int P = 1e9+7;

struct node{
    int u,v,w;
    bool operator<(const node &A){
        return w < A.w;
    }
}edges[N];
int t,n,m,k,u,v,w;
int father[N];
int find(int x){
    int r = x;
    while(r != father[r]){
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
    sort(edges + 1, edges + 1 + m);
    for(int i = 1; i <= n; ++ i){
        father[i] = i;
    }
    int cnt = n, ans = 0;
    for(int i = 1; i <= m; ++ i){
        if(edges[i].w != edges[i - 1].w && cnt == k){
            printf("%d\n",ans);
            return;
        }
        int u = find(edges[i].u), v = find(edges[i].v);
        if(u == v)continue;
        father[u] = v;
        cnt --;
        ans = edges[i].w;
    }
    printf("%d\n", cnt == k ? ans : -1);
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= m; ++ i){
            scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
        }
        solve();
    }
    return 0;
}