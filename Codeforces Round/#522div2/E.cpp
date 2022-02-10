/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-08-31 16:23
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e4 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//只能选相同的值才可以确定。
int n,x,cnt[N],dp[105][N];//dp[i][j]表示前i个物品且体积为j的方案数。
vector<pii> v;
void solve(){
    for(int i = 1; i <= 100; ++ i){
        if(cnt[i])v.push_back({i, cnt[i]});//将占用体积和数量放入。
    }
    dp[0][0] = 1;
    for(auto iter : v){
        int w = iter.first, num = iter.second;
        //cout << w << " " << num << endl;
        //注意先枚举体积。
        for(int j = N - 1; j > 0; -- j){
            for(int i = 1; i <= n; ++ i){
                for(int k = 1; k <= num && k * w <= j && k <= i; ++ k){
                    dp[i][j] += dp[i - k][j - k * w];
                }
            }
        }
    }
    if(v.size() == 2){
        //只有两种
        printf("%d\n", n);
    }
    else{
        int ans = 1;
        for(auto iter : v){
            int w = iter.first, num = iter.second;
            for(int i = 1; i <= num; ++ i){
                if(dp[i][i * w] == 1){
                    ans = max(ans, i);
                }
            }
        }
        printf("%d\n", ans);
    }
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &x);
        ++ cnt[x];
    }
    solve();
    return 0;
}