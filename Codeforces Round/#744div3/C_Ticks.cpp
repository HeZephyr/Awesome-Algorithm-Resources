/**
  *@filename:C_Ticks
  *@author: pursuit
  *@created: 2021-09-28 23:22
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 20 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, m, k;
char s[N][N];
bool vis[N][N];//标记是否可以被染色。
int dfs1(int x, int y, bool flag, int res){
    int ans = 1;
    if(flag && res == 0)return ans;
    if(x - 1 >= 1 && x - 1 <= n && y - 1 >= 1 && y - 1 <= m && s[x - 1][y - 1] == '*'){
        ans += dfs1(x - 1, y - 1, flag, res - 1); 
    }
    if(flag)vis[x][y] = true;
    return ans;
}
int dfs2(int x, int y, bool flag, int res){
    int ans = 1;
    if(flag && res == 0)return ans;
    if(x - 1 >= 1 && x - 1 <= n && y + 1 >= 1 && y + 1 <= m && s[x - 1][y + 1] == '*'){
        ans += dfs2(x - 1, y + 1, flag, res - 1); 
    }
    if(flag)vis[x][y] = true;
    return ans;
}
void solve(){
    bool flag = false;
    for(int i = n; i >= 1; -- i){
        for(int j = m; j >= 1; -- j){
            if(s[i][j] == '*'){
                int x = dfs1(i, j, false, 0) - 1, y = dfs2(i, j, false, 0) - 1;
                //cout << i << " " << j << " " << x << " " << y << endl;
                if(min(x, y) < k && !vis[i][j]){
                    flag = true;
                    break;
                }
                else if(min(x, y) >= k){
                    dfs1(i, j, true, min(x, y) + 1), dfs2(i, j, true, min(x, y) + 1);
                }
            }
        }
        if(flag)break;
    }
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            if(s[i][j] == '*' && !vis[i][j])flag = true;
        }
    }
    if(flag)puts("NO");
    else puts("YES");
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n >> m >> k;
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; ++ i)cin >> s[i] + 1;
        solve();
    }
    return 0;
}