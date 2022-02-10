/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-10-26 18:27
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 5e3 + 10;
const int P = 1e9 + 7;
const ll INF = 1e18;

int t;
ll n, x, y, z;
ll s[N], dp[N][N];//dp[i][j]表示已经输入了前i个字符，且剪贴板内容为当前字符串长度为j的后缀，所需最短时间。剪贴板为0代表剪贴板为空。
int lcs[N][N], pre[N][N];//lcs[i][j]表示前i个字符与前j个字符中的后缀连续子串相同的最大长度。pre[i][j]则表示长度为i的串且后缀长度为j的子串上一个在串中出现的位置。
//我们的目标就是求pre[i][j]
/*
如果重新复制再粘贴，那么f[i][j] = f[i - j][0] + y + z;
如果剪贴板为空，那么久输入单个字符。f[i][0] = f[i - 1][0] + x;
把上一段剪贴板上的内容再粘贴一次：f[i][j] = f[pre[i][j]][j] + (i - pre[i][j] - j) * x + z。
*/
ll solve(){
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < n; ++ j){
            if(s[i] == s[j]){
                lcs[i][j] = (i > 0 && j > 0 ) ? (lcs[i - 1][j - 1] + 1) : 1;
            }
            else{
                lcs[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < i; ++ j){
            pre[i][min(i - j, lcs[i][j])] = j;
        }
    }
    for(int i = 0; i < n; ++ i){
        for(int j = i - 1; j >= 0; -- j){
            pre[i][j] = max(pre[i][j], pre[i][j + 1]);
        }
    }
    dp[0][0] = x;
    for(int i = 1; i < n; ++ i){
        dp[i][0] = dp[i - 1][0] + x;
        for(int j = 1; j <= i; ++ j){
            if(pre[i][j] == -1)continue;
            dp[i][j] = min(dp[i][j], dp[i - j][0] + y + z);
            dp[i][j] = min(dp[i][j], dp[pre[i][j]][j] + 1LL * (i - pre[i][j] - j) * x + z);
            dp[i][0] = min(dp[i][0], dp[i][j]);
        }
    }
    return dp[n - 1][0];
}
int main(){	
    scanf("%d", &t);
    for(int k = 1; k <= t; ++ k){
        scanf("%lld%lld%lld%lld", &n, &x, &y, &z);
        for(int i = 0; i < n; ++ i){
            scanf("%lld", &s[i]);
            for(int j = 0; j < n; ++ j){
                dp[i][j] = INF;
                pre[i][j] = -1;
            }
        }
        printf("Case #%lld: %lld\n", k, solve());
    }
    return 0;
}