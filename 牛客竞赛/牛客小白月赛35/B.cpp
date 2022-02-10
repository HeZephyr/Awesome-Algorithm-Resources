/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-18 19:10
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5000000 + 5;
const int P = 1e9+7;

int n;
ll a[N];
ll get(ll x){
    ll cnt = 0;
    while(x % 2 == 0){
        cnt ++;
        x /= 2;
    }
    return cnt;
}
void solve(){
    ll cnt = 0;
    for(int i = 1; i <= n; ++ i){
        cnt += get(a[i]);
    }
    cout << cnt << endl;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
    }
    solve();
    return 0;
}