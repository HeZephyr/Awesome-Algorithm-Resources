/**
  *@filename:E_Road_Repairs
  *@author: pursuit
  *@created: 2021-08-18 15:36
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

/*
题意：
*/
int n,m,u,v,flag,pre[N],preId[N];
int inCost[N];
int id[N],vis[N],use[N];
struct node{
    int u,v,cost,flag,id;//flag代表道路的状况，若为1，则需要对其进行修复。
}edges[N];
struct Cancel{
    int pre,cur;//pre为可能被取消的那条边的id，而cur保存的是可能新增的那条边的更新前的id。
}cancel[N];
void addEdge(int u,int v,int flag,int id){
    edges[id].u = u;
    edges[id].v = v;
    edges[id].flag = edges[id].cost = flag;
    edges[id].id = id;
}
int zhuliu(int root){
    int res = 0,total = m;//res统计边权和。total为下一条新建边的id。
    while(true){
        for(int i = 1; i <= n; ++ i)inCost[i] = INF, id[i] = vis[i] = -1,pre[i] = -1;//初始化入边消耗等。
        for(int i = 0; i < m; ++ i){
            u = edges[i].u, v = edges[i].v, flag = edges[i].cost;
            if(u != v && flag < inCost[v]){
                //cout << u << "->" << v << endl;
                inCost[v] = flag;
                pre[v] = u;
                //更新加入到边集的那条边的id。
                preId[v] = edges[i].id;
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
            //将新图中用到的边保存起来。
            if(i != root)use[preId[v]] ++;
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
        for(int i = 0; i < m; ++ i){
            int vv = edges[i].v;//由于入边还存着是原来的编号，所以这里取出入边终点。
            //获取重新的编号。
            edges[i].u = id[edges[i].u], edges[i].v = id[edges[i].v];
            if(edges[i].u != edges[i].v){
                //这里看做是环外一点入环内的v点，所以我们需要减去环内入边权。
                //这样可以避免重复计算。
                edges[i].cost -= inCost[vv];//更新权值，因为这个已经被累加了。
                //将这条边的更新信息保存起来。
                cancel[total].pre = preId[vv];//原本指向v的边就取消了。
                cancel[total].cur = edges[i].id;//保留更新前的id。
                edges[i].id = total ++;
            }
        }
        n = tn;//更新新的结点数量。
        root = id[root];//更新根结点编号。
    }
    //正常。
    for(int i = total - 1; i >= m; -- i){
        if(use[i]){
            use[cancel[i].pre] --;
            use[cancel[i].cur] ++;
        }
    }
    return res;
}
void solve(){
    int ans = zhuliu(1);
    printf("%d\n", ans);
    if(ans > 0){
        //找到需要修复的路径编号。
        for(int i = 0; i < m; ++ i){
            if(use[i] && edges[i].flag)printf("%d ", i + 1);
            //cout << i << ":" << use[i] << endl;
        }
        puts("");
    }
}
int main(){	
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout); 
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++ i){
        scanf("%d%d%d", &u, &v, &flag);
        addEdge(u,v,flag,i);
    }
    solve();
    return 0;
}