/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-28 20:02
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 20 + 5;
const int P = 1e9+7;

int n;
int x,y,z;
struct node{
    int u,v,w;
    bool operator < (const node & A){
        return w < A.w;
    }
}edges[N];
int father[N];
int dist[N];
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
    int result = 0x3f3f3f3f;
    sort(edges,edges + n);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n * n; ++ i){
        scanf("%d%d%d", &edges[i].u, &edges[i].v,&edges[i].w);
    }
    solve();
    return 0;
}