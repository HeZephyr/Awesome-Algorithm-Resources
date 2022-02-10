/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-10 19:24
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 300000 + 5;
const int P = 1e9+7;

int t,n,w[N];
struct node1{
    int to,c,next;
}edges[N << 1];
struct node2{
    int u;
    ll c;
};
int head[N],tot;
int u,v,c;
ll maxx;
void init(){
    tot = 0,maxx = 0;
    for(int i = 1; i <= n; ++ i){
        head[i] = 0;
    }
}
void add(int u,int v,int c){
    edges[++ tot].to = u;
    edges[tot].next = head[u];
    edges[tot].c = c;
    head[u] = tot;
}
void solve(){
    node2 head,temp;
    queue<node2> q;
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        init();
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &w[i]);
        }
        for(int i = 0; i < n; ++ i){
            scanf("%d%d%d", &u, &v, &c);
            add(u,v,c);
            add(v,u,c);
        }
        solve();
    }
    return 0;
}