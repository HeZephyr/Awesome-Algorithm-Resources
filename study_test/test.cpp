/**
  *@filename:test
  *@author: pursuit
  *@created: 2021-09-04 19:28
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m, res;
char g[N][N];
int go[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
struct edge{
    int to, next;
} edges[N * N * 100];
int head[N * N], tot;
int q[N * N], st, ed, in[N * N],dist[N * N];
bool vis[N * N];
void add(int u, int v){
    edges[++ tot].to = v;
    edges[tot].next = head[u];  
    head[u] = tot;
}
bool check(int x, int y, int dx, int dy){
    if(g[x][y] == 'Q' && g[dx][dy] == 'W')return true;
    if(g[x][y] == 'W' && g[dx][dy] == 'E')return true;
    if(g[x][y] == 'E' && g[dx][dy] == 'R')return true;
    if(g[x][y] == 'R' && g[dx][dy] == 'Q')return true;
    return false;
}
void init(){
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < m; ++ j){
            for(int k = 0; k < 4; ++ k){
                int di = i + go[k][0], dj = j + go[k][1];
                if(di >= 0 && di < n && dj >= 0 && dj < m && check(i, j, di, dj)){
                    //cout << g[i][j] << " " << g[di][dj] << endl;
                    add(i * m + j, di * m + dj);
                    ++ in[di * m + dj];
                }
            }
        }
    }
}
bool topoSort(){
    bool flag = false;
    st = 1, ed = 0;
    for(int i = 0; i < n * m; ++ i){
        if(!in[i])q[++ ed] = i;
    }
    int u, v;
    while(st <= ed){
        u = q[st ++];
        for(int i = head[u]; i; i = edges[i].next){
            v = edges[i].to;
            //cout << v << endl;
            -- in[v];
            if(!in[v]){
                q[++ ed] = v;
            }
        }
    }
    //cout << ed << endl;
    return ed == n * m;
}
int dfs(int u){
    vis[u] = true;
    int res = 1;
    for(int i = head[u]; i; i = edges[i].next){
        int v = edges[i].to;
        if(!vis[v]){
            vis[v] = true;
            dist[v] = dfs(v);
        }
        res = max(res, dist[v] + 1);
    }
    return res;
}
void solve(){
    init();//加边操作。
    //拓扑检测是否有环。
    if(!topoSort()){
        puts("infinity");
    }
    else{
        //跑最短路。
        fill(dist, dist + N * N, -1);
        int res = 0;
        for(int i = 0; i < n * m; ++ i){
            if(g[i / m][i % m] == 'Q' && !vis[i]){
                dist[i] = dfs(i);
                res = max(res, dist[i]);
            }
        }
        if(res < 4)puts("none");
        else printf("%d\n", res / 4);
    }
}
int main(){	
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++ i){
        scanf("%s", g[i]);
    }
    solve();
    return 0;
}