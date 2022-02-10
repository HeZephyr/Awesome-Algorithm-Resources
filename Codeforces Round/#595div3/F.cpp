/**
  *@filename:F
  *@author: pursuit
  *@created: 2021-08-27 15:37
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 200 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

struct edge{
    int to,next;
}edges[N << 1];
int head[N],tot;
int n,k,a[N],dp[N][N];
int u,v;
void add(int u,int v){
    edges[++ tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void dfs(int u,int fu){
    dp[u][0] = a[u];
    for(int i = head[u]; i; i = edges[i].next){
        v = edges[i].to;
        if(v == fu)continue;
        dfs(v,u);
    }
    for(int depth = 0; depth < n; ++ depth){
        if(depth == 0){
            for(int i = head[u]; i; i = edges[i].next){
                v = edges[i].to;
                if(v == fu)continue;
                dp[u][depth] += dp[v][max(0,k - depth - 1)];
            }
        }
        else{
            for(int i = head[u]; i; i = edges[i].next){
                v = edges[i].to;
                if(v == fu)continue;
                int ans = dp[v][depth - 1];
                for(int j = head[u]; j; j = edges[j].next){
                    int temp = edges[j].to;
                    if(temp == fu || temp == v)continue;
                    ans += dp[temp][max(depth - 1, k - depth - 1)];
                }
                dp[u][depth] = max(dp[u][depth], ans);
            }
        }
    }
    for(int depth = n - 1; depth > 0; -- depth){
        dp[u][depth - 1] = max(dp[u][depth - 1], dp[u][depth]);
    }
}
void solve(){
    dfs(1,-1);
    printf("%d\n", dp[1][0]);
}
int main(){	
    scanf("%d%d", &n, &k);
    ++ k;
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i < n; ++ i){
        scanf("%d%d", &u, &v);
        add(u,v),add(v,u);
    }
    solve();
    return 0;
}