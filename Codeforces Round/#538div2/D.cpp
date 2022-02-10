/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-08-16 15:48
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 5e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,c[N];
int dp[N][N][2];
void solve(){
    //将连通分量缩点，因为已经颜色相同了，便于我们自身处理。
    int cnt = 0;
    int i = 1,j;
    while(i <= n){
        j = i;
        while(j + 1 <= n && c[j + 1] == c[i])j ++;
        c[++cnt] = c[j];
        //cout << c[cnt] << " ";
        i = j + 1;
    }
    n = cnt;
    //初始化。
    for(int i = 1; i <= n; ++ i){
        for(int j = i; j <= n; ++ j){
            dp[i][j][0] = dp[i][j][1] = i == j ? 0 : INF;
        }
    }
    //枚举区间长度。
    int r;
    for(int len = 2; len <= n; ++ len){
        //枚举左端点。
        for(int l = 1; l + len - 1 <= n; ++ l){
            r = l + len - 1;
            //此状态。
            dp[l][r][0] = min(dp[l][r][0],min(dp[l + 1][r][0] + 1, dp[l + 1][r][1] + (c[l] != c[r])));
            dp[l][r][1] = min(dp[l][r][1],min(dp[l][r - 1][0] + (c[l] != c[r]), dp[l][r - 1][1] + 1));
        }
    }
    printf("%d\n", min(dp[1][n][0],dp[1][n][1]));
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &c[i]);
    }
    solve();
    return 0;
}