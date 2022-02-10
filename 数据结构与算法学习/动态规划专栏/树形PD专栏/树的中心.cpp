/**
  *@filename:树的中心
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-25 21:12
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 10000 + 5;
const int P = 1e9+7;

int n;
struct node{
    int v,next,w;
}edges[N << 1];
int tot,head[N];
//这道题实际上和hdu-Computer那道题一样。
int f[N][3];//f[u][0]表示u向下走的最远距离，而f[u][1]表示u向下走的次远距离。f[u][2]则表示u向上走的最远距离。
int son[N];//son[u]表示u向下走的最远距离经过了son[u].
void add(int u,int v,int w){
    edges[++tot].v = v;
    edges[tot].w = w;
    edges[tot].next = head[u];
    head[u] = tot;
}
void dfs_down(int u,int fu){
    for(int i = head[u]; i; i = edges[i].next){
        int v = edges[i].v,w = edges[i].w;
        if(v == fu)continue;
        dfs_down(v,u);
        printf("%d -> %d\n",u,v);
        if(f[u][0] < f[v][0] + w){
            son[u] = v;
            f[u][1] = f[u][0];//继承更新之前的最远距离，这个即为次远距离。
            f[u][0] = f[v][0] + w;
        }
        else if(f[u][1] < f[v][0] + w){
            f[u][1] = f[v][0] + w;//更新次远距离。
        }
    }
}
void dfs_up(int u,int fu){
    //向上跑dfs，所以我们要先更新根结点。
    for(int i = head[u]; i; i = edges[i].next){
        int v = edges[i].v,w = edges[i].w;
        if(v == fu)continue;
        printf("%d -> %d\n",u,v);
        if(son[u] == v){
            //说明最长路径经过了v，我们不能用最长路径来更新v。
            f[v][2] = max(f[u][1],f[u][2]) + w;
        }
        else{
            f[v][2] = max(f[u][0],f[u][2]) + w;
        }
        //printf("%d max:%d\n",u,max(f[u][0],f[u][2]));
        dfs_up(v,u);
    }
}
void solve(){
    printf("-------down-------\n");
    dfs_down(1,-1);
    printf("-------up-------\n");
    dfs_up(1,-1);
    int res = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++){
        res = min(res,max(f[i][0],f[i][2]));
    }
    printf("%d\n",res);
}
int main(){
    scanf("%d",&n);
    int u,v,w;
    for(int i = 1; i < n; i++){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    solve();
    return 0;
}