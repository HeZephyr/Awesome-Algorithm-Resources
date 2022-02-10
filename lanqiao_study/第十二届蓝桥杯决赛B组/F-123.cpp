/**
  *@filename:F-123
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-05 14:30
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2000000 + 5;
const int P = 1e9+7;

ll dp[N];
void init(){
    for(int i = 1; i < N; ++ i){
        dp[i] = dp[i - 1] + i * (i - 1) / 2;
    }
}
void solve(){
}
int main(){
    
    solve();
    return 0;
}