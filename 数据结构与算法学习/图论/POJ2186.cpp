/**
  *@filename:POJ2186
  *@author: pursuit
  *@created: 2021-08-11 13:48
**/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>

#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m;
struct node{
    int to,next;
}edges[N * 5];
int head[N],tot;
bool inStack[N];
int dfn[N],low[N],idx;
int Stack[N],top;
int out[N];//统计出度。
int cnt,belong[N];//cnt为强连通分量个数，belong[u]代表u属于的强连通分量序号。
void init(){
    top = tot = idx = cnt = 0;
    memset(inStack,0,sizeof(inStack));
    memset(dfn,0,sizeof(dfn));
    memset(head,0,sizeof(head));
    memset(out,0,sizeof(out));
}
void add(int u,int v){
    edges[++tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void tarjan(int u){
    dfn[u] = low[u] = ++ idx;
    inStack[u] = true;
    Stack[top ++] = u;
    int v;
    for(int i = head[u]; i; i = edges[i].next){
        v = edges[i].to;
        if(!dfn[v]){
            //说明没有访问过。
            tarjan(v);
            low[u] = min(low[u],low[v]);//更新low。
        }
        else if(inStack[v]){
            //如果在栈中。
            low[u] = min(low[u],dfn[v]);
        }
    }
    if(low[u] == dfn[u]){
        //说明u为该强连通分量的根。
        cnt ++;
        do{
            v = Stack[-- top];
            belong[v] = cnt;
            inStack[v] = false;
        }while(v != u);
    }
}
void solve(){
    for(int i = 1; i <= n; ++ i){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    int sum = 0,ans = 0,temp;
    for(int u = 1; u <= n; ++ u){
        for(int j = head[u]; j; j = edges[j].next){
            int v = edges[j].to;
            if(belong[u] != belong[v]){
                //不属于同一个强连通分量。
                out[belong[u]] ++;
            }
        }
    }
    for(int i = 1; i <= cnt; ++ i){
        //遍历连通分量。
        if(!out[i]){
            //如果为0，说明都属于同一个连通分量。
            sum ++,temp = i;
        }
    }
    if(sum != 1){
        //说明没有或多余1个。
        puts("0");
    }
    else{
        for(int i = 1; i <= n; ++ i){
            if(belong[i] == temp){
                //属于这个强连通分量。
                ans ++;
            }
        }
        printf("%d\n", ans);
    }
}
int main(){	
    while(~scanf("%d%d", &n, &m)){
        init();
        int u,v;
        for(int i = 1; i <= m; ++ i){
            scanf("%d%d", &u, &v);
            add(u,v);
        }
        solve();
    }
    return 0;
}