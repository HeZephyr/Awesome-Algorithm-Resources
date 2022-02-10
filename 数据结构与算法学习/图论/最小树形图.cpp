/**
  *@filename:最小树形图
  *@author: pursuit
  *@created: 2021-08-17 14:34
**/
#include <bits/stdc++.h>

#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e4 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

/*
树形图定义：
对于G = (V,E)，其中具有如下性质
1.G中不包含有向环。
2.存在一个顶点u，它不是任何弧的终点，而且u的其他顶点都恰好是唯一的一条弧的终点。
那么则称G是以u为根的树形图。而最小树形图则是权值最小的那个。
另一种说法：最小树形图，就是给有向带权图一个特殊的点root，
求一棵以root为根节点的树使得该树的的总权值最小。
*/
//判断树形图，我们只需要判断以u作为根结点做一次图的遍历即可。
/*
然后
*/
/*
朱刘算法步骤：
1.对于最小树形图，是绝对不会存在自环的，所以我们需要删除自环，且删除了自环，我们才能保证时间复杂度为O(VE)
2.求最短弧集合E。即我们需要选择除根结点之外的每个点都选定一条入边，这条入边一定是要所有入边最小的。
3.判断集合E中有没有有向环，有就转到步骤4，否则转到步骤5.
4.收缩环。对于有向环，我们需要将其收缩成点，并且对图重新构造，即包括权值的改变和点的处理，然后再回到步骤2
5.展开收缩点得到最小树形图。
*/
int n,m,root;//n个结点m条有向边，以root为根。
int u,v,w;
int g[N][N],inCost[N],pre[N];//inCost[u]存储u的最小入边花费。pre[u]存储u的前驱结点。
int id[N],vis[N];//id[u]表示u重新编号的点，这个数组是为了处理有向环的。vis[u]表示u是通过vis[u]来访问的。
struct node{
    int u,v,w;
}edges[N];
int zhuliu(){
    int res = 0;//res统计边权和。
    while(true){
        for(int i = 1; i <= n; ++ i)inCost[i] = INF, id[i] = vis[i] = -1;//初始化入边消耗等。
        for(int i = 0; i < m; ++ i){
            u = edges[i].u, v = edges[i].v, w = edges[i].w;
            if(u != v && w < inCost[v]){
                inCost[v] = w;
                pre[v] = u;
            }
        }
        for(int i = 1; i <= n; ++ i){
            if(i != root && inCost[i] == INF){
                //说明不存在入边，无法构成树形图。
                return -1;
            }
        }
        inCost[root] = 0;
        int tn = 0;//新的编号。
        for(int i = 1; i <= n; ++ i){
            res += inCost[i];//统计入边消耗。
            v = i;
            while(vis[v] != i && id[v] == -1 && v != root){
                vis[v] = i;
                v = pre[v];//不断迭代前驱结点，知道更新到根结点。若是环，当处于vis[v] = i时即会退出，即回到起点。
            }
            if(v != root && id[v] == -1){
                //说明不是以root为根结点。即出现了有向环
                id[v] = ++tn;
                for(u = pre[v]; u != v; u = pre[u])id[u] = tn;//重新给有向环编号，便于之后缩点。
            }
        }
        if(tn == 0)break;//说明没有重新编号，即不存在有向环。
        for(int i = 1; i <= n; ++ i){
            if(id[i] == -1){
                id[i] = ++tn;//给未重新编号的也重新编号，便于处理。
            }
        }
        int i = 0;
        while(i < m){
            int vv = edges[i].v;//由于入边还存着是原来的编号，所以这里取出入边终点。
            //获取重新的编号。
            edges[i].u = id[edges[i].u], edges[i].v = id[edges[i].v];
            if(edges[i].u != edges[i].v){
                //这里看做是环外一点入环内的v点，所以我们需要减去环内入边权。
                //这样可以避免重复计算。
                edges[i ++].w -= inCost[vv];//更新权值，因为这个已经被累加了。
            }
            else{
                //将有向环环边抛出。
                swap(edges[i],edges[-- m]);
            }
        }
        n = tn;//更新新的结点数量。
        root = id[root];//更新根结点编号。
    }
    return res;
}
void solve(){
    printf("%d\n", zhuliu());
}
int main(){	
    scanf("%d%d%d", &n, &m, &root);
    for(int i = 1; i <= n; ++ i)for(int j = 1; j <= n; ++ j)g[i][j] = INF;
    for(int i = 0; i < m; ++ i){
        scanf("%d%d%d", &u, &v, &w);
        //去除自环。
        if(u == v)continue;
        //去除重边。
        g[u][v] = min(g[u][v],w);
    }
    m = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            //将边存储起来。
            if(g[i][j] != INF){
                edges[m].u = i,edges[m].v = j,edges[m ++].w = g[i][j];
            }
        }
    }
    solve();
    return 0;
}