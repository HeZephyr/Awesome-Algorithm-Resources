/**
  *@filename:大盗阿福
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-26 20:10
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
int w[N];
int f[N];//f[i]表示在前i个商店中，获得的最高价值。
//则我们进行状态划分，对于f[i]，我们其实有两种选择，一种是打劫第i个店，一种是不打劫。
//若打劫，则第i-1个店就不能打劫，故f[i] = f[i- 2] + w[i];
//若不打劫，则第i - 1个店就可以打劫，此时我们考虑前i - 1个。即f[i] = f[i - 1]。
//两者取最大值。
void solve(){
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &w[i]);
        }
        f[1] = w[1];//初始状态。
        for(int i = 2; i <= n; i++){
            f[i] = max(f[i - 1],f[i - 2] + w[i]);
        }
        printf("%d\n",f[n]);
    }
    solve();
    return 0;
}