#include<bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;
const int INF = 0x3f3f3f3f;

int t, n, m, tot;
string s[N];
vector<int> g[N];
int dist[N], vis[N];
int st, ed;
void dijkstra(){
    priority_queue<int, vector<int>, greater<int> > q;
    q.push(st);
    dist[st] = 0;
    int u, v;
    while(!q.empty()){
        u = q.top();
        q.pop();
        if(vis[u])continue;
        vis[u] = 1;
        for(int i = 0; i < g[u].size(); ++ i){
            v = g[u][i];
            if(!vis[v] && dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    if(dist[ed] == INF){
        puts("-1");
    }
    else printf("%d\n", dist[ed] + 1);
}
void solve(){
    for(int i = 0; i < tot; ++ i)dist[i] = INF, vis[i] = 0;
    dijkstra();
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &m);
        int r = n * 5;
        getchar();
        for(int i = 0; i < r; ++ i){
            getline(cin, s[i]);
        }
        tot = n * m - 1;
        solve();
    }
    return 0;
}