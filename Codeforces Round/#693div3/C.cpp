/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-10 08:40
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,n;
ll f[N];//表示到达了i位置，且选取了a[i]所能获得的最大得分。
//则f[i] = f[i + a[i]] + f[i];
void solve(){
    ll maxx = 0;
    for(int i = n; i >= 1; -- i){
        if(i + f[i] <= n){
            f[i] += f[i + f[i]];
        }
        maxx = max(f[i],maxx);
    }
    printf("%lld\n",maxx);
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &f[i]);
        }
        solve();
    }
    return 0;
}