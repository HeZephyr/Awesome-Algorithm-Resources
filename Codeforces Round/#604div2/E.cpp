/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-08-09 19:01
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 998244353;
const int INF = 0x3f3f3f3f;

int n,dp[N],p[N];
int qsm(int n,int q = P - 2){
    int ans = 1;
    while(q){
        if(q & 1){
            ans = 1LL * ans * n % P;
        }
        n = 1LL * n * n % P;
        q >>= 1;
    }
    return ans;
}
void solve(){
    for(int i = 1; i <= n; ++ i){
        dp[i] = 1LL * 100 * (dp[i - 1] + 1) % P * qsm(p[i]) % P;
    }
    printf("%d\n", dp[n]);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
    }
    solve();
    return 0;
}