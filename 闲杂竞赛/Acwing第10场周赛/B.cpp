/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-31 19:02
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n;
ll a[N];
void solve(){
    ll ans = 0;
    for(int i = 1; i <= n - 1; ++ i){
        if(a[i] * 2 == a[n]){
            ans ++;
        }
    }
    printf("%lld\n", ans);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
    }
    solve();
    return 0;
}