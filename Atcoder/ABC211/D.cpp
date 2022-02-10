/**
  *@filename:D
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-24 20:14
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

struct node{
    int to,next;
}edges[N << 1];
int head[N],tot;
int n,m,u,v;
int cnt[N],dist[N];//dist为最短路径数组。dist[i]表示1到i的最短路径。
void add(int u,int v){
    edges[++ tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void bfs(){
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = head[u]; i; i = edges[i].next){
            int v = edges[i].to;
            if(dist[v] == INF){
                //说明没有初始化。
                dist[v] = dist[u] + 1;
                cnt[v] = cnt[u];
                q.push(v);
            }
            else if(dist[v] == dist[u] + 1){
                //说明已经被初始化过了。且最短路径是由此过来的。
                cnt[v] += cnt[u];
                cnt[v] %= P;
            }
        }
    }
}
void solve(){
    fill(dist,dist + N,INF);
    dist[1] = 0;
    cnt[1] = 1;
    bfs();
    cout << cnt[n] << endl;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++ i){
        scanf("%d%d", &u, &v);
        add(u,v),add(v,u);
    }
    solve();
    return 0;
}