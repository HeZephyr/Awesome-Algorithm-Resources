/**
  *@filename:Corn Field G
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-28 16:50
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 10 + 5,M = 10 + 5;
const int P = 1e8;

int n,m;//n行m列的土地。
int a[N][M],st[N];//a代表土地，st代表每一行的土地状况。
bool g[1 << N];//g得到所有状态中的合法状态。
int f[N][1 << N];//f[i][j]表示的则是第i行且状态为j的方案数，是由上一行转移过来的，所以我们定义上一行的状态为k。
//则状态转移方程为f[i][j] += f[i - 1][k];//其中j和k必须满足条件。
void solve(){
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            scanf("%d", &a[i][j]);
        }
    }
    //得到每一行的土地状况。
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            st[i] = (st[i] << 1) + a[i][j];
        }
    }
    //得到所有状态中的合法状态。
    int maxn = 1 << m;//总状态。
    f[0][0] = 1;//初始化，这种也算一种。
    for(int i = 0; i < maxn; ++ i){
        g[i] = !( i & (i << 1));//由于不能相邻，所以我们左移判断是否符合条件。 
    }
    for(int i = 1; i <= n; ++ i){
        //枚举每一行。
        for(int j = 0; j < maxn; ++ j){
            //枚举每一行的状态，判断此状态是否符合条件。1.不能相邻。2.是全部状态的子集。
            if(g[j] && (j & st[i]) == j){
                //如果符合条件。则我们去判断上一行是否符合。
                for(int k = 0; k < maxn; ++ k){
                    //枚举上一行状态。注意，这里我们无需判断上一行状态是否存在，因为不存在即为0.
                    //只需要判断j和k是否存在相邻草地。
                    if(!(j & k)){
                        f[i][j] = (f[i][j] + f[i - 1][k]) % P;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int j = 0; j < maxn; ++ j){
        ans = (ans + f[n][j]) % P;
    }
    printf("%d\n", ans);
    solve();
    return 0;
}