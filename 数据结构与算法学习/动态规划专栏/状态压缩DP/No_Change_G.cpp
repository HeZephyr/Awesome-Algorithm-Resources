/**
  *@filename:No_Change_G
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-28 17:14
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000000 + 5,K = 20;
const int P = 1e9+7;

int n,k;
int g[K];//每个硬币的状态。
int w[K];//硬币的价值
int sum[N];//物品价值的前缀和。
int ans;
int f[1 << K];//f[i]表示在i状态下能够购买的最大物品数。
void solve(){
    //初始化硬币状态。
    g[1] = 1;
    for(int i = 2; i <= k; ++ i){
        g[i] = g[i -1] << 1;
    }
    int maxn = 1 << k;//得到
    for(int i = 0; i < maxn; ++ i){
        //枚举每一种状态。
        for(int j = 1; j <= k; ++ j){
            //枚举所有的硬币。
            if(i & g[j]){
                //说明该硬币在当前状态使用过。
                int te = f[i ^ g[j]];//获取该状态不使用j能获得的物品数。
                te = upper_bound(sum + 1,sum + n + 1,sum[te] + w[j]) - sum;//这里需要减1.
                f[i] = max(f[i],te - 1);
            }
        }
    }
    ll maxx = -2,temp;
    for(int i = 0; i < maxn; ++ i){
        if(f[i] == n){
            //说明该状态能够将所有物品都买完。
            temp = 0;
            for(int j = 1; j <= k; ++ j){
                if(i & g[j]){
                    temp += w[j];
                }
            }
            maxx = max(maxx,ans - temp);
        }
    }
    if(maxx < 0)printf("%d\n", -1);
    else printf("%d\n",maxx);
}
int main(){
    scanf("%d%d", &k , &n);
    for(int i = 1; i <= k; ++ i){
        scanf("%d", &w[i]);
        ans += w[i];//求硬币总价值。
    }
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }
    solve();
    return 0;
}