/**
  *@filename:HDU_2121
  *@author: pursuit
  *@created: 2021-08-17 19:42
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

/*
由于此题是无根的最小树形图，所以我们就要建立一个虚点，也称超级源点，
并使源点到其他所有点都有一条单向路径，且权值为所有路径的权值之和 + 1。
那么最后求得的值为路径的总权值+超级源点到实根的权值。这里做一个sum += 1，
正是为了区分超过最大限度的2 * 路径总权值 + 1的情况，即当超过了说明多了一个实根，这样代表最小树形图不成立。
*/
int n,m,u,v,w,sum,minRoot;
int id[N],vis[N],tot,inCost[N],pre[N];
struct node{
    int u,v,w;
}edges[N * N];
void addEdge(int u,int v,int w){
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot++].w = w;
}
int zhuliu(int root,int n){
    int res = 0;//res统计边权和。
    while(true){
        for(int i = 0; i < n; ++ i)inCost[i] = INF, id[i] = vis[i] = -1;//初始化入边消耗等。
        for(int i = 0; i < tot; ++ i){
            u = edges[i].u, v = edges[i].v, w = edges[i].w;
            if(u != v && w < inCost[v]){
                //cout << u << "->" << v << endl;
                inCost[v] = w;
                pre[v] = u;
                //注意这里，由于前面已经为其余的点分配了入点。剩下的就是可能的实根了。
                if(u == root)minRoot = i;//
                //cout << u << "->" << v << "minRoot:" << minRoot << endl;
            }
        }
        for(int i = 0; i < n; ++ i){
            if(i != root && inCost[i] == INF){
                //说明不存在入边，无法构成树形图。
                return -1;
            }
        }
        inCost[root] = 0;
        int tn = 0;//新的编号。
        //判断是否存在环。
        for(int i = 0; i < n; ++ i){
            res += inCost[i];//统计入边消耗。
            v = i;
            while(vis[v] != i && id[v] == -1 && v != root){
                vis[v] = i;
                v = pre[v];//不断迭代前驱结点，知道更新到根结点。若是环，当处于vis[v] = i时即会退出，即回到起点。
            }
            if(v != root && id[v] == -1){
                //说明不是以root为根结点。即出现了有向环
                for(u = pre[v]; u != v; u = pre[u])id[u] = tn;//重新给有向环编号，便于之后缩点。
                id[v] = tn ++;
            }
        }
        if(tn == 0)break;//说明没有重新编号，即不存在有向环。
        for(int i = 0; i < n; ++ i){
            if(id[i] == -1){
                id[i] = tn ++;//给未重新编号的也重新编号，便于处理。
            }
        }
        int i = 0;
        while(i < tot){
            int vv = edges[i].v;//由于入边还存着是原来的编号，所以这里取出入边终点。
            //获取重新的编号。
            edges[i].u = id[edges[i].u], edges[i].v = id[edges[i].v];
            if(edges[i].u != edges[i].v){
                //这里看做是环外一点入环内的v点，所以我们需要减去环内入边权。
                //这样可以避免重复计算。
                edges[i].w -= inCost[vv];//更新权值，因为这个已经被累加了。
            }
            i ++;
        }
        n = tn;//更新新的结点数量。
        root = id[root];//更新根结点编号。
    }
    return res;
}
void solve(){
    sum ++;
    //添加虚点。
    for(int i = 0; i < n; ++ i){
        addEdge(n,i,sum);
    }
    //更新边数。
    int ans = zhuliu(n,n + 1);
    if(ans == -1 || ans >= 2 * sum){
        puts("impossible");
    }
    else{
        printf("%d %d\n", ans - sum, minRoot - m);
    }
    puts("");
}
int main(){	
    while(~scanf("%d%d", &n, &m)){
        tot = sum = 0;
        for(int i = 0; i < m; ++ i){
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v,w);
            sum += w;
        }
        solve();
    }
    return 0;
}