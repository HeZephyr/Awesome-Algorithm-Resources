/**
  *@filename:B-质数拆分
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-04 16:34
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2020;
const int P = 1e9+7;

//质数拆分。
bool notprimer[N];
int cnt,primer[N];//cnt代表有cnt个质数。
ll dp[N];//dp[j]表示体积为j的总方案数。
void init(){
    notprimer[0] = notprimer[1] = true;
    for(int i = 2; i < N; ++ i){
        if(!notprimer[i]){
            primer[++ cnt] = i;
            for(int j = i * 2; j < N; j += i){
                notprimer[j] = true;
            }
        }
    }
}
void solve(){
    init();
    dp[0] = 1;
    for(int i = 1; i <= cnt; ++ i){
        for(int j = 2019; j >= primer[i]; -- j){
            dp[j] += dp[j - primer[i]];//1941598180
        }
    }
    printf("%d\n",dp[2019]);
}
int main(){
    solve();
    return 0;
}