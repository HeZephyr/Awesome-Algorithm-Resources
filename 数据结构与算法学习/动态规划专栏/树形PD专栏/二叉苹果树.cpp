/**
  *@filename:二叉苹果树
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-24 20:55
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200 + 5;
const int P = 1e9+7;

int n,q;//n为树的结点数，q为要保留的树枝树。根节点编号一定是1.
int f[N][N];
//我们需要知道，当某条边被保留下来的时候，从根节点到这条边的路径的所有边也全部必须被保留下来。
//所以我们设f[u][i]表示u的子树上保留i条边，最多保留的苹果数量。
//则状态转移方程为：
//f[u][i] = max(f[u][i],f[u][i - j - 1] + f[v][j] + e[i].w)
//(1 <= i <= min(q,sz[u]) ,0 <= j <= min(sz[v],i - 1));。
struct Edge{
    int v,next,w;
}edges[N];
int tot,head[N];
int siz[N];//siz[i]表示i的子树有多少条边。
void add(int u,int v,int w){
    edges[++tot].v = v;
    edges[tot].w = w;
    edges[tot].next = head[u];
    head[u] = tot;
}
void dfs(int u,int fu){
    for(int i = head[u]; i != 0; i = edges[i].next){
        int v = edges[i].v,w = edges[i].w;
        if(v == fu)continue;//特判，避免死循环。
        dfs(v,u);
        siz[u] += siz[v] + 1;
        //枚举i和j，即u需要删掉的边，和v需要删掉的边。
        for(int j = min(q,siz[u]); j; j--){
            for(int k = min(siz[v],j - 1); k >= 0; k--){
                f[u][j] = max(f[u][j],f[u][j - k - 1] + f[v][k] + w);//这里是需要保证u和v是连边的。
            }
        }
    }
}
void solve(){
    dfs(1,-1);
    cout << f[1][q] << endl;
}
int main(){
    cin >> n >> q;
    int u,v,w;
    for(int i = 1; i < n; i++){
        cin >> u >> v >> w;
        add(u,v,w);
        add(v,u,w);
    }
    solve();
    return 0;
}