/**
  *@filename:C_Coin_Rows
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-30 23:36
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,m;
ll sum[3][N];
ll ans = 0;
void solve(){
    ll minn = 1e14;
    //枚举断点。
    for(int j = 1; j <= m; ++ j){
        ll maxx = 0;
        maxx = max(maxx,sum[1][m] - sum[1][j]);
        maxx = max(maxx,sum[2][j - 1]);
        minn = min(minn,maxx);
    }
    cout << minn << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> m;
        for(int i = 1; i <= 2; ++ i){
            for(int j = 1; j <= m; ++ j){
                cin >> sum[i][j];
                ans += sum[i][j];
                sum[i][j] += sum[i][j - 1];
            }
        }
        solve();
    }
    return 0;
}