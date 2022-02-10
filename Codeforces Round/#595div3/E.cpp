/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-08-27 12:25
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,c,a[N],b[N];
int dp[N][2];
void solve(){
    dp[1][0] = a[1];
    dp[1][1] = b[1] + c;
    for(int i = 2; i < n; ++ i){
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i];
        dp[i][1] = min(dp[i - 1][0] + c, dp[i - 1][1]) + b[i];
    }
    for(int i = 0; i < n; ++ i){
        printf("%d%c", min(dp[i][0], dp[i][1]), i == n - 1 ? '\n' : ' ');
    }
}
int main(){	
    scanf("%d%d", &n, &c);
    for(int i = 1; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i < n; ++ i){
        scanf("%d", &b[i]);
    }
    solve();
    return 0;
}