/**
  *@filename:A_Strange_Partition
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-02 19:08
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,x;
int a[N];
void solve(){
    ll ans1 = 0,ans2 = 0,temp = 0;
    for(int i = 1; i <= n; ++ i){
        ans1 += a[i] / x;
        ans2 += a[i] / x + (a[i] % x != 0);
        temp +=(a[i] % x);
    }
    cout << ans1 + temp / x + (temp % x != 0) << " " << ans2 << endl;
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n , &x);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}