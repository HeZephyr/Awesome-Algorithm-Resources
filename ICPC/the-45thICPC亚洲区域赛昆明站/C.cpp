/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-10-20 18:18
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 5e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N], b[N];//n个城市，第i个城市属于ai。
int dp[N][N];
void solve(){
    int tot = 0;
    int last = 0;
    //去重。
    for(int i = 1; i <= n; ++ i){
        if(b[i] != last){
            a[++ tot] = b[i];
            last = b[i];
        }
    }
    n = tot;
    /* for(int i = 1; i <= tot; ++ i){
        cout << a[i] << " ";
    }
    cout << endl; */
    for(int len = 2; len <= n; ++ len){
        for(int i = 1, j; i + len - 1 <= n; ++ i){
            j = i + len - 1;
            dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            //cout << "i: " << i << " j: " << j << " dp[i][j] " << dp[i][j] << endl;
            if(a[i] == a[j]){
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + 1);
            }
            else{
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + 2);
            }
        }
    }
    cout << dp[1][n] << endl;
    //初始化。
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            dp[i][j] = 0;
        }
    }
}
int main(){	
    /* scanf("%d", &t);
    while(t -- ){ */
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &b[i]);
        }
        solve();
   /*  } */
    return 0;
}