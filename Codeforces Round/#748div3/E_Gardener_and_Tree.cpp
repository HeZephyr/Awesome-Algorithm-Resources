/**
  *@filename:E_Gardener_and_Tree
  *@author: pursuit
  *@created: 2021-10-13 23:21
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 4e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, k, tot;
bool vis[N];
struct Edge{
    int to, next;
}edges[N << 1];
struct node{
    int u, cnt;
};
int head[N], du[N];
void add(int u, int v){
    edges[++ tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void init(){
    for(int i = 1; i <= n; ++ i)head[i] = du[i] = 0;
    tot = 0;
}
void solve(){
    if(n == 1){
        puts("0");
        return;
    }
    queue<node> q;
    int res = n;
    for(int i = 1; i <= n; ++ i){
        if(du[i] == 1){
            -- du[i];
            q.push({i, 1});
            -- res;
        }
    }
    while(!q.empty()){
        node temp = q.front();
        if(temp.cnt == k || res == 0)break;
        q.pop();
        for(int i = head[temp.u]; i; i = edges[i].next){
            int v = edges[i].to;
            -- du[v];
            if(du[v] == 1)q.push({v, temp.cnt + 1}), -- res;
        }
    }
    printf("%d\n", res);
    init();
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &k);
        tot = 0;
        for(int i = 1, u, v; i < n; ++ i){
            scanf("%d%d", &u, &v);
            add(u, v), add(v, u);
            ++ du[u], ++ du[v];
        }
        solve();
    }
    return 0;
}