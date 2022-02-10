/**
  *@filename:A_K_divisible_Sum
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-26 20:41
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
ll n,k;
void solve(){
    if(k < n){
        k = ceil(1.0 * n / k) * k;
    }
    int ans = ceil(1.0 * k / n);
    cout << ans << endl;
}

int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> k;
        solve();
    }
    return 0;
}