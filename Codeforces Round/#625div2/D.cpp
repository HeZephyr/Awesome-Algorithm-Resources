/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-09-03 10:12
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m, k;
struct edge{
    int to, next;
} edges1[N << 2], edges2[N];
int head1[N], tot1, head2[N], tot2;
int dist[N];
int p[N];
void add1(int u, int v){
    edges1[++ tot1].to = v;
    edges1[tot1].next = head1[u];
    head1[u] = tot1;
}
void add2(int u, int v){
    edges2[++ tot2].to = v;
    edges2[tot2].next = head2[u];
    head2[u] = tot2;
}
void bfs(){
    queue<int> q;
    dist[p[k]] = 0;
    q.push(p[k]);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = head2[u]; i; i = edges2[i].next){
            int v = edges2[i].to;
            if(dist[v] == INF){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
void solve(){
    fill(dist, dist + N, INF);
    bfs();
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i < k; ++ i){
        int u = p[i];
        if(dist[u] == dist[p[i + 1]] + 1){
            int cnt = 0;
            for(int j = head1[u]; j; j = edges1[j].next){
                int v = edges1[j].to;
                if(dist[u] == dist[v] + 1){
                    ++ cnt;
                }
                if(cnt == 2){
                    ++ cnt2;
                    break;
                }
            }
        }
        else{
            ++ cnt1, ++ cnt2;
        }
    }
    printf("%d %d\n", cnt1, cnt2);
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1, u, v; i <= m; ++ i){
        scanf("%d%d", &u, &v);
        add1(u, v), add2(v, u);
    }
    scanf("%d", &k);
    for(int i = 1; i <= k; ++ i){
        scanf("%d", &p[i]);
    }
    solve();
    return 0;
}
