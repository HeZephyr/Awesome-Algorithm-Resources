/**
  *@filename:1003
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-22 13:15
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

struct node{
    int to,next;
}edges[N];
int head[N],tot,u,v;
int t,n,m,x,y,z;
void add(int u,int v){
    edges[++ tot].next = head[u];
    edges[tot].to = v;
    head[u] = tot;
}
void solve(){
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n, &m);
        scanf("%d", &x, &y, &z);
        for(int i = 1; i <= m; ++ i){
            scanf("%d%d", &u, &v);
            add(u,v);
            add(v,u);
        }
    }
    solve();
    return 0;
}