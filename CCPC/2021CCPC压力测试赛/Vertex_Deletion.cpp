/**
  *@filename:Vertex_Deletion
  *@author: pursuit
  *@created: 2021-09-05 15:56
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 998244353;
const int INF = 0x3f3f3f3f;

//对于此题，首先我们需要选定一个作为根节点。假设为1.
//那么对于每个点所有三种形式：删除，保留至少一个子节点相连，保留并且不和任何子节点相连，即子节点全部删除。
int dp[N][3];//则表示这三种形式。
int t, n;
struct edge{
    int to, next;
}edges[N << 1];
int head[N], tot;
void add(int u, int v){
    edges[++ tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void dfs(int u, int fu){
    dp[u][0] = dp[u][1] = dp[u][2] = 1;
    for(int i =  head[u]; i; i = edges[i].next){
        int v = edges[i].to;
        if(v == fu)continue;
        dfs(v, u);
        //cout << u << "->" << v << endl;
        //由于该节点删除，故子节点所有行为都不管。
        dp[u][0] = 1LL * dp[u][0] * (dp[v][0] + dp[v][1]) % P;
        dp[u][2] = 1LL * dp[u][2] * dp[v][0] % P;//该点删除，那么子节点也肯定删除了。
        //由于保留至少一个子节点相连。所以这里会统计所有结点的情况，然后多出了dp[u][2]的情况。
        dp[u][1] = 1LL * dp[u][1] * (dp[v][0] + dp[v][1] + dp[v][2]) % P; 
        //debug(dp[u][0]), debug(dp[u][1]), debug(dp[u][2]);
    }
    dp[u][1] -= dp[u][2];
    if(dp[u][1] < 0)dp[u][1] += P;
}
void solve(){
    //由于是相乘。
    dfs(1, -1);
    printf("%lld\n", 1LL * (dp[1][0] + dp[1][1]) % P);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        tot = 0;
        fill(head, head + N, 0);
        for(int i = 0, u, v; i < n - 1; ++ i){
            scanf("%d%d", &u, &v);
            add(u, v), add(v, u);
        }
        solve();
    }
    return 0;
}