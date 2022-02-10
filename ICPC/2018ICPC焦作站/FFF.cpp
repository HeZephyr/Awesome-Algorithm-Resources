#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
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
        for(int i = 0; i < g[u].size(); ++ i){
            v = g[u][i];
            if(dist[v] == INF){
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
void bfs(){
    queue<int> q;
    q.push(st);
    dist[st] = 0;
    int u, v, w;
    while(!q.empty()){
        u = q.front();
        q.pop();
        if(u == ed){
            printf("%d\n", dist[u] + 1);
            return;
        }
        for(auto v : g[u]){
            if(dist[v] == INF){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    puts("-1");
}
void solve(){
    for(int i = 0; i < tot; ++ i)dist[i] = INF;
    bfs();
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
        int idx1;
        for(int i = 0; i <= tot; ++ i) g[i].clear();
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                int idx = i * m + j;
                int x = i * 4 + ((j % 2) ? 4 : 2);
                int y = j * 6; 
                if(s[x][y + 4] == 'S')st = idx;
                else if(s[x][y + 4] == 'T')ed = idx;
                if(s[x + 2][y + 3] != '-'){
                    idx1 = idx + m;
                    if(idx > tot)continue;
                    g[idx].push_back(idx1);
                    g[idx1].push_back(idx);
                }
                if(s[x - 1][y + 7] != '\\'){
                    if(j % 2 == 0){
                        idx1 = idx - m + 1;
                        if(idx1 < (i - 1) * m || idx1 > i * m - 1)continue;
                    }
                    else{
                        idx1 = idx + 1;
                        if(idx1 < i * m || idx1 > (i + 1) * m - 1)continue;
                    }
                    if(idx1 <= 0 || idx1 > tot)continue;
                    g[idx1].push_back(idx);
                    g[idx].push_back(idx1);
                }
                if(s[x + 1][y + 7] != '/'){
                    if(j % 2 == 0){
                        idx1 = idx + 1;
                        if(idx1 < i * m || idx1 > i * m + m - 1)continue;
                    }
                    else{
                        idx1 = idx + m + 1;
                        if(idx1 < (i + 1) * m || idx1 > (i + 1) * m + m - 1)continue;
                    }
                    if(idx1 > tot)continue;
                    g[idx1].push_back(idx);
                    g[idx].push_back(idx1);
                }
            }
        }
        /* cout << "S: " << st << "; T:" << ed << endl;
        for(int i = 0; i <= tot; ++ i){
            for(auto j : g[i]){
                cout << i << "->" << j << endl;
            }
        } */
        solve();
    }
    return 0;
}