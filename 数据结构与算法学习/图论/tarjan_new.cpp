/**
  *@filename:tarjan_new
  *@author: pursuit
  *@created: 2021-08-11 12:50
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//链式前向星存图。
struct node{
    int to,next;
}edges[N];
int head[N],tot;
int n,m;//顶点数和边数。
//dfn[u]表示u的dfs序号，low[u]表示以u所在连通子图对应的子树的所有结点中最小的dfs序号值。
//易知，low[u] = min(tree dfn[v],v \in tree)。
int dfn[N],low[N];
bool inStack[N];//inStack[u]判断u是否在栈中。
int Stack[N],top,idx;//idx为编号，Stack为栈，top为栈顶指针。
int cnt;//为强连通分量的个数。
int belong[N],num[N];//belong[u]表示u所在的连通分量序号,num[i]表示第i个强连通分量的顶点数。
void add(int u,int v){
    edges[++tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void tarjan(int u){
    dfn[u] = low[u] = ++ idx;//将节点u设置dfs序，同时设置low的初值。
    Stack[top ++] = u;//入栈。
    inS0ack[u] = true;//标记入栈。
    int v;
    for(int i = head[u]; i; i = edges[i].next){
        v = edges[i].to;
        if(!dfn[v]){
            //判断v是否被访问过。即是否设置了dfs序。
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        //判断是否在栈中。
        else if(inStack[v]){
            low[u] = min(low[u],dfn[v]);
        }
    }
    //判断当前是否为强连通分量的根。
    if(low[u] == dfn[u]){
        cnt ++;
        do{
            v = Stack[-- top];
            inStack[v] = false;
            belong[v] = cnt;
            num[cnt] ++;
        }while(v != u);
    }
}
void solve(){
    for(int i = 1; i <= n; ++ i){
        if(!dfn[i]){
            tarjan(i);
        }
    }
}
int main(){	
    solve();
    return 0;
}