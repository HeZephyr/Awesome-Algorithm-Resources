/**
  *@filename:POJ3177
  *@author: pursuit
  *@created: 2021-08-14 10:55
**/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//将一个有桥连通图变成一个边双连通图。然后再缩点得到一棵树，那么需要考虑所有度为1的点。
//即端点，因为必然要在这些点上连边，不然最终一定会有割边。
//给du
struct node{ 
    int to,next;
    bool cut;//是否为割边。
}edges[N];
int head[N],tot;
int dfn[N],low[N],num;
int Stack[N],belong[N],top,cnt;//栈，belong[u]表示u属于哪个连通块。
bool inStack[N];//标记是否入栈。
int n,m;//n个顶点m条边。
int du[N];
void add(int u,int v){
    edges[tot].to = v;
    edges[tot].next = head[u];
    edges[tot].cut = false;
    head[u] = tot ++;
}
void init(){
    memset(head,-1,sizeof(head));
    tot = top = cnt = num = 0;
    memset(du,0,sizeof(du));
    memset(dfn,0,sizeof(dfn));
    memset(inStack,false,sizeof(inStack));
}
void tarjan(int u,int fu){
    dfn[u] = low[u] = ++ num;
    Stack[top ++] = u;
    inStack[u] = true; 
    int v;
    for(int i = head[u]; ~i; i = edges[i].next){
        v = edges[i].to;
        //cout << u << "->" << v << endl;
        if(v == fu)continue;
        if(!dfn[v]){
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
            if(dfn[u] < low[v]){
                cnt ++;//为桥。
                edges[i].cut = true;
                edges[i ^ 1].cut = true;
            }
        }
        else if(inStack[v] && dfn[v] < low[u]){
            low[u] = dfn[v];
        }
    }
    if(dfn[u] == low[u]){
        cnt ++;
        do{
            v = Stack[-- top];
            belong[v] = cnt;
            inStack[v] = false;
        }while(u != v);
    }
}
void solve(){
    tarjan(1,0);
    for(int u = 1; u <= n; ++ u){
        for(int i = head[u]; ~i; i = edges[i].next){
            if(edges[i].cut){
                //判断是否为割边。
                du[belong[u]] ++;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= cnt; ++ i){
        if(du[i] == 1){
            ans ++;
        }
    }
    printf("%d\n", (ans + 1) / 2);
}
int main(){	
    while(~scanf("%d%d", &n, &m)){
        init();
        int u,v;
        for(int i = 1; i <= m; ++ i){
            scanf("%d%d", &u, &v);
            add(u,v),add(v,u);
        }
        solve();
    }
    return 0;
}