/**
  *@filename:D
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-03 14:18
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const ll mod = 1e9+7;

int n,m,k;
ll dp[maxn];
void solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[j]=(dp[j]+dp[j-1]+1)%mod;
        }
    }
    cout<<dp[m]<<endl;
}
int main(){
    cin>>n>>m>>k;
    solve();
    return 0;
}