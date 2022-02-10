/**
  *@filename:皇宫看守
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-25 15:47
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 3000 + 5;
const int P = 1e9+7;

int n;//树中结点的数目。
ll w[N];//w[i]表示在i宫殿安置侍卫所需的经费k。
bool vis[N];
struct node{
    int v,next;
}edges[N];
int tot,head[N];
//这题我们需要知道，和战略游戏不一样，维护一个点可以是自己，也可以是父亲结点，也可以是孩子结点。所以状态其实有三个。
ll f[N][3];//其中f[u][0]表示在u宫殿不安置侍卫，而让其父节点处放置守卫，以它构成的子树所需的最少经费，
//而f[u][1]则是在u宫殿不安置侍卫,而让其子节点放置的守卫看护，以它构成的子树所需的最少经费。
//f[u][2]则是在u宫殿安置侍卫，以它构成的子树所需的最少经费。
//我们易知，若u结点不设置侍卫，则孩子结点或者父亲结点必须设置。
//则易知f[u][0] += min(f[v][1],f[v][2]);//由于u宫殿没有安置侍卫，所以它的子节点有两种选择。
//f[u][1] = min(f[u][1],sum - min(f[v][1],f[v][2]) + f[v][2]);//这个意义代表如果u宫殿由子节点v守护，那么所有的子节点都不能由父节点守卫，
//并且每个节点都得到了守卫，且至少有一个子节点放置了守卫，由于u宫殿不设置守卫，所以v只有两种选择。
//f[u][2] += min(min(f[v][0],f[v][1]),f[v][2]);//当在u宫殿安置侍卫了，它的孩子结点有三种选择。
int root;
void add(int u,int v){
    edges[++tot].v = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void dfs(int u,int fu){
    f[u][2] = w[u];
    f[u][0] = 0;
    int sum = 0;
    for(int i = head[u]; i; i = edges[i].next){
        int v = edges[i].v;
        if(v == fu)continue;
        dfs(v,u);
        f[u][0] += min(f[v][1],f[v][2]);
        f[u][2] += min(min(f[v][0],f[v][1]),f[v][2]);
        sum += min(f[v][1],f[v][2]);
    }
    f[u][1] = 0x3f3f3f3f;
    //开始枚举放置守卫的子节点。
    for(int i = head[u]; i; i = edges[i].next){
        int v = edges[i].v;
        if(v == fu)continue;
        f[u][1] = min(f[u][1],sum - min(f[v][1],f[v][2]) + f[v][2]);
    }
}
void solve(){
    //printf("%d\n",root);
    dfs(root,-1);
    printf("%lld\n",min(f[root][1],f[root][2]));
}
int main(){
    scanf("%d",&n);
    int u,v,siz;
    for(int i = 1; i <= n; i++){
        scanf("%d",&u);
        scanf("%lld%d",&w[u],&siz);
        for(int j = 0; j < siz; j++){
            scanf("%d",&v);
            add(u,v);
            vis[v] = true;
        }
    }
    root = 1;
    while(vis[root])root ++;
    solve();
    return 0;
}