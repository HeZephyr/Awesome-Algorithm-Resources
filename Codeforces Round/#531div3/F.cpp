/**
  *@filename:F
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-28 10:11
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 18,M = 1e4 + 5;
const int P = 1e9+7;
const int INF = 0x3f3f3f3f;

int n,m;
int a[N][M],kk[N][N];//kk[i][j]表示序号i的行和序号j的行的min(k)
//此题需要注意的细节就是无论行序号怎么交换，两个行之间的k是不变的。我们相当于是要凑最大的k。
//状压DP。
int dp[1 << N][N];//dp[i][j]就表示状态为i的时候且到达了j行的最大k。需要注意i的二进制上的1表示该行已经遍历了。
void init(){
    for(int i1 = 0; i1 < n; ++ i1){
        for(int i2 = i1 + 1; i2 < n; ++ i2){
            int k = INF;
            //遍历取最小值。
            for(int j = 0; j < m; ++ j){
                k = min(k,abs(a[i1][j] - a[i2][j]));
            }
            kk[i1][i2] = kk[i2][i1] = k;
        }
    }
}
void solve(){
    init();
    int sn = 1 << n;
    int ans = 0;
    //首先枚举起点。
    for(int st = 0; st < n; ++ st){
        memset(dp,0,sizeof(dp));
        dp[1 << st][st] = INF;//设为INF是为了保证能从这个点出发。
        //枚举状态。
        for(int s = 0; s < sn; ++ s){
            //枚举当前行。
            for(int i1 = 0; i1 < n; ++ i1){
                if(dp[s][i1]){
                    //枚举下一行。
                    for(int i2 = 0; i2 < n; ++ i2){
                        if(!(s & 1 << i2)){
                            //判断这个点是否访问过，如果没有，我们从这个点出发。获取这一行和上一行的最小差值的最大值。
                            dp[s | 1 << i2][i2] = max(dp[s | 1 << i2][i2],min(dp[s][i1],kk[i1][i2]));
                        }
                    }
                }
            }
        }
        //枚举终点。因为我们最后一行是接着上一行的，这也决定了k的值。
        for(int ed = 0; ed < n; ++ ed){
            int k = dp[sn - 1][ed];
            for(int j = 0; j + 1 < m; ++ j){
                k = min(k,abs(a[ed][j] - a[st][j + 1]));
            }
            ans = max(ans,k);
        }
    }
    printf("%d\n", ans);
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < m; ++ j){
            scanf("%d", &a[i][j]);
        }
    }
    solve();
    return 0;
}