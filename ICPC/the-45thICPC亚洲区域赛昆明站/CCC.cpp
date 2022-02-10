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

int t, n, a[N];//n个城市，第i个城市属于ai。
int dp[N][N];
vector<int> v[N];
void solve(){
    int tot = 0;
    int last = 0;
    //去重。
    for(int i = 1; i <= n; ++ i){
        if(a[i] != last){
            last = a[i];
            a[++ tot] = a[i];
            v[a[tot]].push_back(tot);
        }
    }
    n = tot;
    /* for(int i = 1; i <= tot; ++ i){
        cout << a[i] << " ";
    }
    cout << endl; */
    for(int len = 2; len <= n; ++ len){
        for(int i = 1; i + len - 1 <= n; ++ i){
            int j = i + len - 1;
            dp[i][j] = dp[i][j - 1] + 1;
            for(auto &x : v[a[j]]){
                if(x >= i && x < j){
                    dp[i][j] = min(dp[i][j], dp[i][x] + dp[x + 1][j]);
                }
            }
        }
    }
    cout << dp[1][n] << endl;
    for(int i = 1; i <= n; ++ i){
        dp[i][i] = 0;
        v[i].clear();
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}