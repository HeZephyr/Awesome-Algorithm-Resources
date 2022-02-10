#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e3 + 10;
const int INF = 0x3f3f3f3f;
struct node{
    int v, w;
    bool operator < (const node &A) const {
        return w > A.w;
    }
};
struct edge{
    int v, w;
    edge(int _v = 0, int _w = 0) : v(_v), w(_w) {}
};
vector<edge> g[N];
int dist[N];
bool vis[N];
int n, m, c;
void addedge(int u, int v, int w){
    g[u].push_back(edge(v, w));
}
void dijkstar(int st){
    for(int i = 1; i <= n; ++ i){
        if(i == st)dist[st] = INF;
        else dist[i] = INF;
        vis[i] = false;
    }
    priority_queue<node> q;
    for(auto iter : g[st]){
        dist[iter.v] = iter.w;
        q.push({iter.v, iter.w});
    }
    node head, temp;
    while(!q.empty()){
        head = q.top();
        q.pop();
        int u = head.v;
        if(vis[u])continue;
        vis[u] = true;
        for(int i = 0; i < g[u].size(); ++ i){
            int v = g[u][i].v, w = g[u][i].w;
            if(!vis[v] && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                q.push({v, dist[v]});
            }
        }
    }
}
int main(){
    scanf("%d%d%d", &n, &m, &c);
    int minEdge = INF;
    for(int i = 1, u, v, w;i <= m;i++){
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w);
        minEdge = min(minEdge, w);
    }
    int minn = INF;
    for(int i = 1; i <= n; ++ i){
        dijkstar(i);
        //cout << dist[i] << " ";
        minn = min(minn, dist[i]);
    }
    if(c >= minn){
        puts("2");
    }
    else if(c >= minEdge){
        puts("1");
    }
    else{
        puts("0");
    }
    return 0;
}