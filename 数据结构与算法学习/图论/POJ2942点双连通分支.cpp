/**
  *@filename:POJ2942点双连通分支
  *@author: pursuit
  *@created: 2021-08-14 15:05
**/
//#include <bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//首先我们需要把仇恨关系处理成非仇恨关系的图
int n,m;
struct node{
    int to,next;
}edges[N * N * 4];
int head[N],tot;
bool relation[N][N];//relation[u][v]表示u和v的关系。
bool inStack[N],can[N];//color染色。can表示能不能留在骑士军团。
int Stack[N],top;
int dfn[N],low[N],num;
int temp[N],cnt;//临时存储双连通分量中的点。cnt记录有多少个点。
bool ok[N];//表示ok[u]是否属于当前连通分支。
int color[N];//染色。
void init(){
    memset(head,0,sizeof(head));
    memset(relation,0,sizeof(relation));
    memset(inStack,false,sizeof(inStack));
    memset(dfn,0,sizeof(dfn));
    memset(can,false,sizeof(can));
    top = num = tot = 0;
}
void add(int u,int v){
    edges[++tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
int dfs(int u,int c){
    color[u] = c;
    for(int i = head[u]; i; i = edges[i].next){
        int v = edges[i].to;
        if(ok[v]){
            if(color[v] != -1){
                //说明已经被初始化了。
                if(color[v] == c)return false;
            }
            else if(!dfs(v,!c)){
                return false;
            }
        }
    }
    return true;
}
void tarjan(int u,int fu){
    dfn[u] = low[u] = ++ num;
    Stack[top ++] = u;
    inStack[u] = true;
    int v;
    for(int i = head[u]; i; i = edges[i].next){
        v = edges[i].to;
        if(v == fu)continue;
        if(!dfn[v]){
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
            if(dfn[u] <= low[v]){
                //则u为割点。
                memset(ok,0,sizeof(ok));
                cnt = 0;
                int vv;
                do{
                    vv = Stack[-- top];
                    temp[++cnt] = vv;
                    ok[vv] = true;
                    inStack[vv] = false;
                }while(v != vv);
                ok[u] = true;
                memset(color,-1,sizeof(color));
                if(!dfs(u,0)){
                    //如果不是二分图，则这些点可以存在。
                    can[u] = true;
                    for(int j = 1; j <= cnt; ++ j)can[temp[j]] = true;
                }
            }
        }
        else if(inStack[v]){
            low[u] = min(low[u],dfn[v]);
        }
    }
}
void solve(){
    for(int i = 1; i <= n; ++ i){
        if(!dfn[i]){
            tarjan(i,0);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++ i){
        if(!can[i]){
            ans ++;
        }
    }
    printf("%d\n", ans);
}
int main(){	
    while(~scanf("%d%d", &n, &m) && (n + m)){
        int u,v;
        init();
        for(int i = 1; i <= m; ++ i){
            scanf("%d%d", &u, &v);
            relation[u][v] = relation[v][u] = true;
        }
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= n; ++ j){
                if(i != j && !relation[i][j]){
                    add(i,j),add(j,i);
                }
            }
        }
        solve();
    }
    return 0;
}