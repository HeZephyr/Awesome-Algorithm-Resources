/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-10-29 20:33
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m;//数组长度都为m，元素取值范围为[1, n]。ai <= bi， a中元素非严格单调递增， b中元素非严格单调递减。
ll dp[20][2][1100];//dp[i][0/1][j]表示前i个元素，0表示递增，1表示递减，且最后一个元素为j。
void solve(){
    for(int j = 1; j <= n; ++ j){
        dp[1][0][j] = dp[1][1][j] = 1;
    }
    for(int i = 2; i <= m; ++ i){
        for(int j = 1; j <= n; ++ j){
            //枚举前i个元素，且第i个元素为j。枚举有多少种可能即可。
            for(int k = 1; k <= j; ++ k){
                dp[i][0][j] = (dp[i][0][j] + dp[i - 1][0][k]) % P;
            }
            for(int k = j; k <= n; ++ k){
                dp[i][1][j] = (dp[i][1][j] + dp[i - 1][1][k]) % P;
            }
        }
    }
    ll res = 0;
    for(int j = 1; j <= n; ++ j){
        for(int k = j; k <= n; ++ k){
            res = (res + dp[m][0][j] * dp[m][1][k]) % P;
        }
    }
    printf("%lld\n", res);
}
int main(){	
    scanf("%d%d", &n, &m);
    solve();
    return 0;
}