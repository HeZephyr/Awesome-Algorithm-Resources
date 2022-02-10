/**
  *@filename:国际象棋
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-02 13:14
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 7,M = 101,K = 21;
const int P = 1e9+7;

int n,m,k;
ll f[M][1 << N][1 << N][K];//f[i][j][u][cnt]代表前m列，已经放好了，且当前列为j状态。
//前一列状态为u状态,且已经放置了cnt个马。
int maxn,num[1 << N];//num[i]为i状态所放置的马数。
int get(int x){
    int sum = 0;
    while(x){
        sum ++;
        x &= (x - 1);
    }
    return sum;
}
void init(){
    maxn = 1 << n;
    for(int i = 0; i < maxn; ++ i){
        num[i] = get(i);
    }
}
void solve(){
    init();
    f[0][0][0][0] = 1;
    for(int i = 1; i <= m; ++ i){
        //枚举当前列的状态。
        for(int j = 0; j < maxn; ++ j){
            //枚举上一列的状态。
            for(int u = 0; u < maxn; ++ u){
                //判断当前列与前一列是否存在冲突。
                if((j & (u << 2)) || (j & (u >> 2)))continue;
                //枚举上上一列的状态。
                for(int v = 0; v < maxn; ++ v){
                    //判断上上一列和当前列是否存在冲突。
                    if((j & (v << 1)) || (j & (v >> 1)))continue;
                    //判断上上一列是否与前一列存在冲突。
                    if((u & (v << 2)) || (u & (v >> 2)))continue;
                    for(int cnt = num[j]; cnt <= k; ++ cnt){
                        f[i][j][u][cnt] = (f[i][j][u][cnt] + f[i - 1][u][v][cnt - num[j]]) % P;
                    }
                    //printf("%d %d %d:%d\n",j,u,v,f[i][j][u][num[j]]);
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < maxn; ++ i){
        for(int j = 0; j < maxn; ++ j){
            ans = (ans + f[m][i][j][k]) % P;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    scanf("%d %d %d", &n, &m, &k);
    solve();
    return 0;
}