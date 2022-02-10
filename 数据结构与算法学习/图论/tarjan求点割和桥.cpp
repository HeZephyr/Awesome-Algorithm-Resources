/**
  *@filename:tarjan求点割和桥
  *@author: pursuit
  *@created: 2021-08-12 11:01
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 3e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//模板题：割点。
//割点：去掉该顶点和相邻的所有边，连通分量增加。
//割边或边：去掉一条边，图中的连通分量数增加。
//性质：有割点不一定有桥，有桥一定有割点。
//若顶点u的所有孩子结点可以不通过父结点u而访问到u的祖先结点，那么说明此时去掉u不影响图的连通性。 
//这是显而易见的。而如果顶点u至少存在一个孩子结点必须通过父结点u才能访问到u的祖先结点，那么去掉
//结点u之后，孩子结点无法访问到u的祖先结点，不连通，说明u是割点。
//特殊的一点在于根结点不存在祖先结点，
//那么我们判断实际上就可以根据根结点如果能一次dfs就能访问完所有的结点，那么根结点就不是割点。
//综上，如果一个结点u是割点，则当且仅当满足下列条件1或2.
//1.如果结点u是总的dfs树的根，那么该结点u有多余1个的子树。
//2.如果结点u不是总的dfs树的根，那么该结点u存在一颗子树，子树的根结点为u，使得dfn[u] <= low[v]。
//如果一条边(u,v)是桥，当且仅当边(u,v)没有重边，且dfn[u] < low[v]。
int dfn[N],low[N],num;//dfs序，low[u]表示不通过父结点所能访问到的最小的dfs序。
int n,m;//顶点数和边数。
//链式前向星。
struct node{
    int v,next;
}edges[N];
struct edge{
    int u,v;
};
int head[N],tot;
vector<int> cutP;//存储割点。
vector<edge> cutE;//存储割边。
void add(int u,int v){
    edges[++ tot].v = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void tarjan(int u,int fu){
    //由于是无向图，所以这里避免回到u的父结点。
    dfn[u] = low[u] = ++ num;
    bool flag = false;//判断是否为根结点。
    int son = 0;//统计子节点。
    for(int i = head[u]; i; i = edges[i].next){
        int v = edges[i].v;
        if(v == fu)continue;
        //cout << u << "->" << v <<  endl;
        if(!dfn[v]){
            //没有被访问过。
            son ++;
            tarjan(v,u);
            if(dfn[u] <= low[v]){
                flag = true;//说明u是割点。
            }
            if(dfn[u] < low[v]){
                //说明为割边。
                cutE.push_back({u,v});
            }
            low[u] = min(low[u],low[v]);
        }
        else{
            low[u] = min(low[u],dfn[v]);
        }
    }
    //如果fu为0，说明当前是根结点。
    if((!fu && son > 1) || (fu && flag)){
        cutP.push_back(u);
    }
}
void solve(){
    for(int i = 1; i <= n; ++ i){
        if(!dfn[i]){
            tarjan(i,0);
        }
    }
    sort(cutP.begin(),cutP.end());
    printf("%d\n", cutP.size());
    for(auto &x : cutP){
        printf("%d ", x);
    }
    puts("");
}
int main(){	
    scanf("%d%d", &n, &m);
    int u,v;
    for(int i = 1; i <= m; ++ i){
        scanf("%d%d", &u, &v);
        add(u,v),add(v,u);
    }
    solve();
    return 0;
}