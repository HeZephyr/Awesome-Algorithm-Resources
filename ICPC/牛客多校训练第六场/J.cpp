/**
  *@filename:J
  *@author: pursuit
  *@created: 2021-09-26 19:19
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 2e9;


//删去非割点显然只需要删除一个，所以考虑删掉割点的情况取最优即可。
//我们删除割点的时候一定不会删除掉非割点。
int t, n, m, a[N];
struct node{
    int to, next;
}edges[N << 1];
int head[N], tot;
void add(int u, int v){
    edges[++ tot].next = head[u], edges[tot].to = v, head[u] = tot;
}
int idx, low[N], dfn[N];
int siz[N];//siz[i]表示以i为结点的子树结点数总和。
bool cut[N], tag[N];//cut[i]表示i结点是否为割点， tag[i]表示i这个割点割去之后剩下的连通块城市数量是否为偶数。
ll res;
void init(){
    tot = idx = 0;
    res = 0;
    for(int i = 1; i <= n; ++ i)head[i] = low[i] = dfn[i] = siz[i] = 0, cut[i] = tag[i] = false;
}
void tarjan(int u, int fu){
    dfn[u] = low[u] = ++ idx;
    int v, son = 0;
    siz[u] = 1;
    for(int i = head[u]; i; i = edges[i].next){
        v = edges[i].to;
        if(v == fu)continue;
        if(!dfn[v]){
            ++ son;
            tarjan(v, u);
            siz[u] += siz[v];
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u]){
                if(fu)cut[u] = true;//为割点。
                if(siz[v] & 1){
                    //说明子树结点为奇数。
                    tag[u] = true;
                }
            }
        }
        else{
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(!fu && son > 1)cut[u] = true;
}
void solve(){
    if(n % 2 == 0){
        printf("%lld\n", res);
        init();
        return;
    }
    tarjan(1, 0);
    int minn = INF;
    for(int i = 1; i <= n; ++ i){
        if(!cut[i] || !tag[i]){
            //cout << a[i] << " ";
            minn = min(minn, a[i]);
        }
    }
    //cout << endl;
    printf("%lld\n", res - 2 * minn);
    init();
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            res += a[i];
        }
        for(int i = 1, u, v; i <= m; ++ i){
            scanf("%d%d", &u, &v);
            add(u, v), add(v, u);
        }
        solve();
    }
    return 0;
}