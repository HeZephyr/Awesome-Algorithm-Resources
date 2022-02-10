/**
  *@filename:G
  *@author: pursuit
  *@created: 2021-09-01 15:52
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, m, u, v;
struct edge{
    int to, next;
}edges[N];
int head[N], tot;
int dist[N], dp[N][2];
void add(int u, int v){
    edges[++ tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void bfs(){
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int i = head[u]; i; i = edges[i].next){
            v = edges[i].to;
            if(dist[v] == INF){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
int dfs(int u, int flag){
    //flag为1表示还有一次机会可以选择第二种操作。否则不可选择。
    if(dp[u][flag] != -1)return dp[u][flag];
    dp[u][flag] = dist[u];
    for(int i = head[u]; i; i = edges[i].next){
        int v = edges[i].to;
        if(dist[u] < dist[v]){
            dp[u][flag] = min(dp[u][flag], dfs(v,flag));
        }
        else if(flag){
            dp[u][flag] = min(dp[u][flag], dfs(v, 0));
        }
    }
    return dp[u][flag];
}
void solve(){
    bfs();
    //开始dp。
    for(int i = 1; i <= n; ++ i){
        printf("%d ", min(dfs(i, 0), dfs(i, 1)));
    }
    puts("");
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &m);
        memset(head, 0, sizeof(head));
        memset(dp, -1, sizeof(dp));
        fill(dist, dist + N, INF);
        tot = 0;
        for(int i = 1; i <= m; ++ i){
            scanf("%d%d", &u, &v);
            add(u, v);
        }
        solve();
    }
    return 0;
}