/**
  *@filename:Game_Map
  *@author: pursuit
  *@created: 2021-08-21 14:06
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m,u,v;
//邻接表。
struct edge{
    int to,next;
}edges[N * 10];
int head[N],tot;
int dp[N],du[N],id[N];//id存储由小到达增长的点。
bool cmp(int i,int j){
    return du[i] < du[j];
}
void add(int u,int v){
    edges[++tot].next = head[u];
    edges[tot].to = v;
    head[u] = tot;
}
void solve(){
    sort(id, id + n,cmp);
    int ans = 0;
    for(int i = 0; i < n; ++ i){
        u = id[i];
        for(int j = head[u]; j; j = edges[j].next){
            v = edges[j].to;
            //遍历其接下来的。
            if(du[v] > du[u]){
                dp[v] = max(dp[v],dp[u] + 1);
            }
        }
        ans = max(ans,dp[u]);
    }
    printf("%d\n", ans);
}
int main(){	
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++ i)id[i] = i,dp[i] = 1;//自身也算一个。
    for(int i = 0; i < m; ++ i){
        scanf("%d%d", &u, &v);
        add(u,v),add(v,u);
        du[u] ++,du[v] ++;
    }
    solve();
    return 0;
}