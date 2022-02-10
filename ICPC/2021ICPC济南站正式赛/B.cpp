#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+7;

int t, n;
struct e_node{
    int next;
    int to;
}e[maxn << 1];
int head[maxn];
int tot;
void add_e(int u, int v){
    e[++tot].to = v;
    e[tot].next = head[u];
    head[u] = tot;
}
int sz[maxn];
void dfs1(int u, int father){
    sz[u] = 1;
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(v == father)continue;
        dfs1(v, u);
        sz[u] += sz[v];
    }
}
int ans;
void dfs(int u, int father){
    for(int i = head[u]; i; i = e[i].next){
        int v = e[i].to;
        if(v == father)continue;
        ans += sz[1] - 1 - 
    }
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1, u, v; i < n; ++ i){
            scanf("%d%d", &u, &v);
            add_e(u, v);
        }
    }
    return 0;
}