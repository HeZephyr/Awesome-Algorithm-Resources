/**
  *@filename:D
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-04 20:24
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f;
const int N = 410;
const int P = 1e9+7;

int n,m;
int u,v,w;
ll a[N][N];
int dist[N][N];
void solve(){
    ll ans = 0;
    for(int k = 1; k <= n; ++ k){
        fill(dist[0],dist[0] + N * N,INF);
        for(int s = 1; s <= n; ++ s){
            for(int t = 1; t <= n; ++ t){
                dist[s][t] = min(a[s][t],a[s][k] + a[k][t]);
                if(a[s][t] < INF){
                    ans += dist[s][t];
                }
            }
        }
        for(int i = 1; i<= n; ++ i){
            for(int j = 1; j <= n; ++ j){
                a[i][j] = dist[i][j];
            }
        }
    }
    cout << ans  << endl;
}
int main(){
    scanf("%d%d", &n, &m);
    fill(a[0],a[0] + N * N,INF);
    for(int i = 1; i <= n; ++ i){
        a[i][i] = 0;
    }
    for(int i = 1; i <= m; ++ i){
        scanf("%d%d%d", &u, &v, &w);
        if(w < a[u][v]){
            a[u][v] = a[v][u] = w;
        }
    }
    solve();
    return 0;
}