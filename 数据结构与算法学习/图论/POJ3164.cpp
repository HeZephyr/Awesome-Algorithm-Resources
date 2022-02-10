/**
  *@filename:POJ3164
  *@author: pursuit
  *@created: 2021-08-17 19:47
**/
//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl
#define x first 
#define y second
using namespace std;

typedef pair<double, double> pdd;
typedef long long ll;
const int N = 100 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m,u,v,pre[N];
double w,inCost[N];
int id[N],vis[N],tot;
pdd a[N];
struct node{
    int u,v;
    double w;
}edges[N * N];
double getDist(int u,int v){
    return sqrt((a[u].x - a[v].x) * (a[u].x - a[v].x) + (a[u].y - a[v].y) * (a[u].y - a[v].y));
}
void addEdge(int u,int v){
    edges[++tot].u = u;
    edges[tot].v = v;
    edges[tot].w = getDist(u,v);
}
double zhuliu(int root){
    double res = 0;//res统计边权和。
    while(true){
        for(int i = 1; i <= n; ++ i)inCost[i] = INF, id[i] = vis[i] = -1;//初始化入边消耗等。
        for(int i = 1; i <= m; ++ i){
            u = edges[i].u, v = edges[i].v, w = edges[i].w;
            if(u != v && w < inCost[v]){
                //cout << u << "->" << v << endl;
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
        int i = 1;
        while(i <= m){
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
                swap(edges[i],edges[m --]);
            }
        }
        n = tn;//更新新的结点数量。
        root = id[root];//更新根结点编号。
    }
    return res;
}
void solve(){
    double ans = zhuliu(1);
    if(ans == -1){
        puts("poor snoopy");
    }
    else{
        printf("%.2f\n", ans);
    }
}
int main(){	
    while(~scanf("%d%d", &n, &m)){
        tot = 0;
        for(int i = 1; i <= n; ++ i){
            scanf("%lf%lf", &a[i].x, &a[i].y);
        }
        for(int i = 0; i < m; ++ i){
            scanf("%d%d", &u, &v);
            if(u == v)continue;
            addEdge(u,v);
        }
        m = tot;
        solve();
    }
    return 0;
}