/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-18 17:23
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 5e2 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,m;
char s[N][N];
int dp[N][N];
int dfs(int x,int y){
    if(dp[x][y])return dp[x][y];
    //判断能否继续向下拓展。
    if(x + 1 <= n && s[x + 1][y] == '*' && y - 1 >= 1 && s[x + 1][y - 1] == '*' 
    && y + 1 <= m && s[x + 1][y + 1] == '*'){
        return dp[x][y] = 1 + min(dfs(x + 1,y),min(dfs(x + 1,y - 1),dfs(x + 1,y + 1)));
    }
    else{
        return dp[x][y] = 1;//不能向下拓展，说明只有它自己。
    }
}
void solve(){
    int ans = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            if(s[i][j] == '*'){
                ans += dfs(i,j);
            }
        }
    }
    printf("%d\n", ans);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++ i){
            scanf("%s", s[i] + 1);
            for(int j = 1; j <= m; ++ j){
                dp[i][j] = 0;
            }
        }
        solve();
    }
    return 0;
}