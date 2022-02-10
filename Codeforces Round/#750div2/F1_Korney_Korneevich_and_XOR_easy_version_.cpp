/**
  *@filename:F1_Korney_Korneevich_and_XOR_easy_version_
  *@author: pursuit
  *@created: 2021-10-25 09:08
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, a[N];
int dp[N][510];//dp[i][j]表示前i个数，且最后一个数是j的异或值。
void solve(){
    set<int> res;
    for(int i = 1; i <= n; ++ i){
        for(int j = 0; j <= 500; ++ j){
            res.insert(dp[i - 1][j]);
            if(j <= a[i]){
                dp[i][a[i]] = dp[i - 1][j] ^ a[i];
            }
        }
    }
    cout << res.size() << endl;
    for(auto x : res){
        cout << x << " ";
    }
    cout << endl;
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}