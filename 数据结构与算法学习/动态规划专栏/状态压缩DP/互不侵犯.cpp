/**
  *@filename:互不侵犯
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-31 16:32
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 10;
const int P = 1e9+7;

int n,m;
int tot,num[1 << N];//num[i]表示第i种可行状态的国王所放数量。
ll f[N][1 << N][N * N];//f[i][j][k]表示前i行，当前处于j状态且已经放置了k个国王。
int get(int x){
    //获取该状态有多少国王。
    int sum = 0;
    for(int i = 0; i < n; ++ i){
        sum += (x & 1);
        x >>= 1;
    }
    return sum;
}
void init(){
    int maxn = 1 << n;
    for(int i = 0; i < maxn; ++ i){
        if(i & (i << 1))continue;//说明存在相邻的。
        num[i] = get(i);
        f[1][i][num[i]] = 1;
    }
}
void solve(){
    init();
    int maxn = 1 << n;
    for(int i = 2; i <= n; ++ i){
        for(int j = 0; j < maxn; ++ j){
            //枚举所有状态。
            if(j & (j << 1))continue;
            for(int k = 0; k < maxn; ++ k){
                //枚举上一行的所有状态。
                if(((k & (k << 1)) || j & k || ((j << 1) & k) || (j & (k << 1)))){
                    continue;
                }
                for(int cnt = num[j]; cnt <= m; ++ cnt){
                    f[i][j][cnt] += f[i - 1][k][cnt - num[j]];
                }
            }
        }
    }
    ll ans = 0;
    for(int  i= 0; i < maxn; ++ i){
        ans += f[n][i][m];
    }
    printf("%lld\n",ans);
}
int main(){
    scanf("%d %d", &n, &m);
    solve();
    return 0;
}