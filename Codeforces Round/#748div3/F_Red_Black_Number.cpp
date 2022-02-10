/**
  *@filename:F_Red_Black_Number
  *@author: pursuit
  *@created: 2021-10-16 15:58
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 50 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

bool dp[N][N][N][N];//dp[u][ma][mb][cnta]表示考虑第u位且当前选取数A模a为ma，当前选取数B模b为mb，且A为cnta位的状态是否被访问过.
int t, n, a, b, res;
bool vis[N], ok[N];//vis[i]表示第i个数是否被A选取。
string s;
void dfs(int u, int ma, int mb, int cnta){
    if(u == n){
        if(!ma && !mb && cnta && cnta < n){
            if(abs(n - 2 * cnta) < res){
                res = abs(n - 2 * cnta);
                for(int i = 0; i < n; ++ i)ok[i] = vis[i];
            }
        }
        return;
    }
    if(dp[u][ma][mb][cnta])return;
    dp[u][ma][mb][cnta] = true;
    vis[u] = false;
    dfs(u + 1, ma, (mb * 10 + s[u] - '0') % b, cnta);
    vis[u] = true;
    dfs(u + 1, (ma * 10 + s[u] - '0') % a, mb, cnta + 1);
}
void solve(){
    dfs(0, 0, 0, 0);
    if(res == 1e9){
        puts("-1");
        return;
    }
    for(int i = 0; i < n; ++ i){
        if(ok[i])printf("R");
        else printf("B");
    }
    puts("");
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n >> a >> b;
        cin >> s;
        res = 1e9;
        memset(dp, false, sizeof(dp));
        solve();
    }
    return 0;
}