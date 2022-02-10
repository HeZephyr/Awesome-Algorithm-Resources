/**
  *@filename:炮兵阵地
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-01 12:26
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5,M = 11;
const int P = 1e9+7;

//注意此题原本有2^10状态，而由于同行同列炮塔之间间距至少为2，则状态最多60.
int n,m;
int st[N];//st[i]表示第i行的地图情况。
int g[N];//g[i]表示第i个合法状态的十进制数。
int cnt[N];//cnt[i]表示第i个状态放置了多少炮兵。
int f[N][N][N];//f[i][j]表示前i行，且第i行为第j个合法状态，且第i - 1行为第k个合法状态的最大炮兵部队摆放数量。
char s[N][M];
int tot;//总共有的合法数量。
int get(int x){
    int sum = 0;
    while(x){
        sum ++ ;
        x &= (x - 1);
    }
    return sum;
}
void init(){
    int maxn = 1 << m;
    tot = 0;
    for(int i = 0; i < maxn; ++ i){
        if((i & (i << 1)) || (i & (i << 2)))continue;
        g[ ++ tot] = i;
        cnt[tot] = get(i);
        //printf("%d -> %d %d:%d\n",tot,g[tot],i,cnt[tot]);
    }
}
void solve(){
    init();
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            st[i] = (st[i] << 1) + (s[i][j] == 'P');
        }
    }
    memset(f,-1,sizeof(f));
    //初始化第1行。
    for(int i = 1; i <= tot; ++ i){
        if((g[i] & st[1]) == g[i])f[1][i][1] = cnt[i];//假定第一行的前一行状态全为0.
    }
    for(int i = 2; i <= n; ++ i){
        //枚举当前行状态。
        for(int j = 1; j <= tot; ++ j){
            //判断当前状态和当前行是否冲突。
            if((st[i] & g[j]) == g[j]){
                //枚举前一行的状态。判断是否与当前状态冲突。
                for(int k = 1; k <= tot; ++ k){
                    if(!(g[j] & g[k])){
                        //枚举前二行状态。
                        for(int l = 1; l <= tot; ++ l){
                            if(!(g[j] & g[l])){
                                f[i][j][k] = max(f[i][j][k],f[i - 1][k][l] + cnt[j]);
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int j = 1; j <= tot; ++ j){
        for(int k = 1; k <= tot; ++ k){
            ans = max(ans,f[n][j][k]);
        }
    }
    printf("%d\n",ans);
}
int main(){
    scanf("%d %d", &n ,&m);
    for(int i = 1; i <= n; ++ i){
        scanf("%s",s[i] + 1);
    }
    solve();
    return 0;
}