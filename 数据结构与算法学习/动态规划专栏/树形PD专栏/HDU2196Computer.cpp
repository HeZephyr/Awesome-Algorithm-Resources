/**
  *@filename:HDU-Computer
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-19 21:47
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 20010;
const int P = 1e9 + 7;

int n;
ll f[N][3];//其中我们可以用f[i][0]表示i节点孩子部的最远点距离，f[i][1]表示为i节点孩子部的次远点距离。f[i][1]表示为i节点父亲部的最远距离。
struct Edge{
    //next为当前边的下一条边，to为此边终点，w为边权值。
    int next,to;
    ll w;
}edges[N];
int head[N],tot;//head[i]表示以i为起点的第一条边的编号，若为-1则表示该起点没有边。tot则表示边的编号。
int son[N];//son[u]表示u的最大路径经过了son[u].
void add(int u,int v,ll w){
    //加边函数。
    tot++;
    edges[tot].to = v;
    edges[tot].w = w;
    edges[tot].next = head[u];
    head[u] = tot;//改变第一条边的编号。
}
void init(){
    //初始化。
    tot = 0;
    memset(head,-1,sizeof(head));
    memset(f,0,sizeof(f));
    memset(son,0,sizeof(son));
}
void dfs1(int u,int fu){
    //第一遍dfs。求出每个点u向下的最大距离和次大距离。并且用son[u]记录最大路径经过了与u直接相邻的哪一个子节点。
    for(int i = head[u]; i != -1; i = edges[i].next){
        int v = edges[i].to;
        if(v == fu)continue;
        int w = edges[i].w;
        dfs1(v,u);//递归子树。
        if(f[u][0] < f[v][0] + w){
            son[u] = v;//记录最大路径的子树节点。
            f[u][1] = f[u][0];//更新次大距离。
            f[u][0] = f[v][0] + w;
        }
        else if(f[u][1] < f[v][0] + w){
            f[u][1] = f[v][0] + w;
        }
    }
}
void dfs2(int u,int fu){
    //第二遍dfs，对于当前节点u，如果满足son[u] = v;说明u的最大路径经过了v，
    //v一定不能通过u的最大路来更新答案。只能通过u的次大路。而u的次大路一定的那个不会经过v。
    for(int i = head[u]; i != -1; i = edges[i].next){
        int v = edges[i].to;
        int w = edges[i].w;
        if(v == fu)continue;
        if(son[u] != v){
            f[v][2] = max(f[u][0],f[u][2]) + w;
        }
        else{
            f[v][2] = max(f[u][1],f[u][2]) + w;
        }
        dfs2(v,u);
    }
}
void solve(){
    dfs1(1,0);
    f[1][2] = f[1][1];//根节点的路径一样。
    dfs2(1,0);
    for(int i = 1; i <= n; i++){
        cout << max(f[i][2],f[i][0]) << endl;
    }
}
int main(){
    while(cin >> n){
        init();
        int y;
        ll z;
        for(int x = 2; x <= n; x++){
            cin >> y >> z;
            add(x,y,z);
            add(y,x,z);
        }
        solve();
    }
    return 0;
}