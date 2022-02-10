/**
  *@filename:tarjan缩点
  *@author: pursuit
  *@created: 2021-08-13 16:43
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 3e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//模板题P387.
//缩点，就是将一张有环图中的环缩成一个点，从而形成一个有向无环图。
//链式前向星。
struct node{
    int u,v,next;
}edges[N],edges2[N];
int head[N],tot,head2[N];
int dfn[N],low[N],num;
int n,m;//n个顶点m条边。
int Stack[N],top;//栈，存储连通分量。
bool inStack[N];//判断是否在栈中。
int sd[N],w[N];//sd[u]表示所对应的新点。w[n]为点权。
//dp[u] = max(dp[u],dp[v] + p[u]);
int in[N],dp[N];//in[u]表示u的入度。
void add(int u,int v){
    edges[++ tot].v = v;
    edges[tot].u = u;
    edges[tot].next = head[u];
    head[u] = tot;
}
void add2(int u,int v){
    edges2[++ tot].u = u;
    edges2[tot].v = v;
    edges2[tot].next = head2[u];
    head2[u] = tot;
}
void tarjan(int u){
    dfn[u] = low[u] = ++ num;
    Stack[top ++] = u;
    inStack[u] = true;
    int v;
    for(int i = head[u]; i; i = edges[i].next){
        v = edges[i].v;
        if(!dfn[v]){
            //如果没有出边过。
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(inStack[v]){
            low[u] = min(low[u],dfn[v]);
        }
    }
    if(dfn[u] == low[u]){
        //说明此为强连通分量根结点。
        do{
            v = Stack[-- top];
            inStack[v] = false;
            sd[v] = u;
            if(u == v)break;
            w[u] += w[v];
        }while(u != v);
    }
}
int topoSort(){
    queue<int> q;
    for(int i = 1; i <= n; ++ i){
        if(sd[i] == i && !in[i]){
            //找到起始点。
            q.push(i);
            dp[i] = w[i];
        }
    }
    int u,v;
    for(int u = 1; u <= n; ++ u)
    //puts("topoSort");
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int i = head2[u]; i; i = edges2[i].next){
            v = edges2[i].v;
            //printf("%d -> %d\n", u, v);
            dp[v] = max(dp[v],dp[u] + w[v]);
            in[v] --;
            if(in[v] == 0)q.push(v);//直到路径走完再开始由起点出发。
        }
    }
    int res = 0;
    for(int i = 1; i <= n; ++ i){
        res = max(res,dp[i]);
    }
    return res;
}
void solve(){
    for(int i = 1; i <= n; ++ i){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    int u,v;
    tot = 0;
    for(int i = 1; i <= m; ++ i){
        u = sd[edges[i].u], v = sd[edges[i].v];
        //printf("%d->%d\n", u, v);
        if(u != v){
            //u = v说明已经缩成一个点了。
            add2(u,v);
            in[v] ++;
        }
    }
    //拓扑排序求DAGdp。
    printf("%d\n", topoSort());
}
int main(){	
    scanf("%d%d", &n, &m);
    int u,v;
    //重复经过的点，权值只计算一次。
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &w[i]);
    }
    for(int i = 1; i <= m; ++ i){
        scanf("%d%d", &u, &v);
        add(u,v);
    }
    solve();
    return 0;
}