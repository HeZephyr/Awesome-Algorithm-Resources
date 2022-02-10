/**
  *@filename:最大路径权值
  *@author: pursuit
  *@created: 2021-08-22 10:23
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 3e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m,u,v;
struct edge{
    int to,next;
}edges[N];
char s[N];
int head[N],tot;
int du[N],f[N];//存储入度。
int q[N],st,ed;//队列。存储
void add(int u,int v){
    edges[++tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
bool topoSort(){
    st = 0,ed = -1;
    for(int i = 1; i <= n; ++ i){
        if(!du[i]){
            q[++ ed] = i;
        }
    }
    while(st <= ed){
        u = q[st ++];
        for(int i = head[u]; i; i = edges[i].next){
            v = edges[i].to;
            -- du[v];
            if(!du[v]){
                q[++ ed] = v;
            }
        }
    }
    return ed == n - 1;
}
void solve(){
    if(!topoSort())puts("-1");
    else{
        int res = 0;
        for(char c = 'a'; c <= 'z'; ++ c){
            for(int i = n - 1; i >= 0; -- i){
                u = q[i];//取当前点。
                int x = f[u] = (c == s[u]);
                for(int j = head[u]; j; j = edges[j].next){
                    v = edges[j].to;
                    f[u] = max(f[u], x + f[v]);
                }
                res = max(f[u],res);
            }
        }
        printf("%d\n", res);
    }
}
int main(){	
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for(int i = 0; i < m; ++ i){
        scanf("%d%d", &u, &v);
        add(u,v);
        ++ du[v];
    }
    solve();
    return 0;
}