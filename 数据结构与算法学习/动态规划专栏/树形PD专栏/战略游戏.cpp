/**
  *@filename:战略游戏
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-24 21:39
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 3010;
const int P = 1e9+7;

int n;//树的节点数目。
struct node{
    int v,next;
}edges[N];
int tot,head[N];
int f[N][2];//f[i][0]表示不选择当前节点，那么子节点必选择，而f[i][1]表示选择当前节点，那么子节点可不选。
bool vis[N];//判断根节点。
int root;
void add(int u,int v){
    edges[++tot].v = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void dfs(int u,int fu){
    //当前的花费。
    f[u][0] = 0;
    f[u][1] = 1;
    for(int i = head[u]; i; i = edges[i].next){
        int v = edges[i].v;
        if(v == fu)continue;
        dfs(v,u);
        f[u][1] += min(f[v][0],f[v][1]);
        f[u][0] += f[v][1];
    }
}
void solve(){
    dfs(root,-1);
    printf("%d\n",min(f[root][0],f[root][1]));
}
int main(){
    while(scanf("%d",&n)!=EOF){
        memset(vis,false,sizeof(vis));
        memset(head,0,sizeof(head));
        tot = 0;
        int u,v,siz;
        for(int i = 0; i < n; i++){
            scanf("%d:(%d)",&u,&siz);
            for(int j = 0; j < siz; j++){
                scanf("%d",&v);
                add(u,v);
                vis[v] = true;
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                root = i;
                break;
            }
        }
        solve();
    }
    return 0;
}