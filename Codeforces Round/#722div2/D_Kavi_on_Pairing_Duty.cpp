/**
  *@filename:D_Kavi_on_Pairing_Duty
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-25 14:54
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000000 + 5;
const int P = 998244353;

int dp[N],v[N];
int n;
void solve(){
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j+=i){
            v[j] ++;
        }
    }
    int sum = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = (v[i] + sum) % P;
        sum = (sum + dp[i]) % P;
    }
    cout << dp[n] << endl;
    solve();
    return 0;
}