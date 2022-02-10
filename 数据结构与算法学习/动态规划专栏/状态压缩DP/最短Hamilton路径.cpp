/**
  *@filename:最短Hamilton路径
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-01 15:15
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 21;
const int P = 1e9+7;

int n,a[N][N];//a[i][j]表示i到j的距离。
int f[1 << N][N];//f[i][j]表示当前状态为i，且当前处于第j个点的最短路径。
int g[1 << N];//各个点的状态。
void solve(){
    int maxn = 1 << n;
    fill(f[0],f[0] + (1 << N) * N,0x3f3f3f3f);
    g[1] = 1;
    for(int i = 2; i <= n; ++ i){
        g[i] = g[i - 1] << 1;
    }
    //初始化最初的状态。
    for(int i = 1; i <= n; ++ i){
        f[g[i]][i] = a[1][i];
    }
    //求解状态。
    for(int i = 0; i < maxn; ++ i){
        for(int j = 1; j <= n; ++ j){
            if(i & g[j]){
                //枚举前一个状态。
                for(int k = 1; k <= n; ++ k){
                    if((j != k) && (i & g[k])){
                        //也需要包含k。
                        f[i][j] = min(f[i][j],f[i - g[j]][k] + a[j][k]);
                    }
                }
            }
        }
    }
    printf("%d\n",f[maxn - 1][n]);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            scanf("%d", &a[i][j]);
        }
    }
    solve();
    return 0;
}