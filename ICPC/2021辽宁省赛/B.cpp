#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 500 + 10;
const ll INF = 1e14;
int n, m;
ll a[N];
ll res[N][N], dp1[N][N], dp2[N][N];
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
    }
    fill(dp2[0], dp2[0] + N * N, INF);
    for(int i = 1, u, v, w; i <= m; ++ i){
        scanf("%d%d%d", &u, &v, &w);
        dp1[u][v] = dp1[v][u] = w;
        dp2[u][v] = dp2[v][u] = a[u] + a[v];
    }
    for(int k = 1; k <= n; ++ k){
        for(int i = 1; i <= n; ++ i){
            if(!dp1[i][k])continue;
            for(int j = 1; j <= n; ++ j){
                if(!dp1[k][j])continue;
                dp1[i][j] = max(dp1[i][j], dp1[i][k] + dp1[k][j]);
            }
        }
    }
    for(int k = 1; k <= n; ++ k){
        for(int i = 1; i <= n; ++ i){
            if(dp2[i][k] >= INF)continue;
            for(int j = 1; j <= n; ++ j){
                if(dp2[k][j] >= INF)continue;
                dp2[i][j] = min(dp2[i][j], dp2[i][k] + dp2[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            if(i == j)printf("0 ");
            else if(dp1[i][j] == 0)printf("1 ");
            else printf("%lld ", dp1[i][j] * ((dp2[i][j] + a[i] + a[j]) / 2));
        }
        puts("");
    }
    return 0;
}