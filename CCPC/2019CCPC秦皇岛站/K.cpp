#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
struct e_node{
    int to;
    int next;
}e[maxn << 1];
int head[maxn], tot;
void add_e(int u, int v){
    e[++tot].to = v;
    e[tot].next = head[u];
    head[u] = tot;
}
int sz[maxn], p[maxn];
void dfs(int u, int father){
    sz[u] = 1;
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[v] % 2 == 0)p[u]++;
    }
}
int n, m;
void init(){
    for(int i = 1; i <= n; ++i){
        sz[i] = p[i] = head[i] = 0;
    }
    tot = 0;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        init();
        scanf("%d", &n);
        for(int i = 2; i <= n; ++i){
            int x;
            scanf("%d", &x);
            add_e(x, i);
            add_e(i, x);
        }
        dfs(1, 0);
        
    }
}