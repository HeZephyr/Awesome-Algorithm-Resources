/**
  *@filename:C_MAX_MEX_Cut
  *@author: pursuit
  *@created: 2021-09-12 22:47
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n;
char s[2][N];
bool vis[N];
void solve(){
    int res = 0;
    for(int i = 1; i <= n; ++ i){
        if(s[0][i] != s[1][i]){
            vis[i] = true;
            res += 2;
        }
    }
    for(int i = 1; i < n; ++ i){
        if(!vis[i] && !vis[i + 1] && (s[0][i] != s[0][i + 1] 
        || s[1][i] != s[1][i + 1] || s[0][i] != s[1][i + 1] || s[1][i] != s[0][i + 1])){
            res += 2;
            vis[i] = vis[i + 1] = true;
        }
    }
    for(int i = 1; i <= n; ++ i){
        if(!vis[i] && s[0][i] == '0'){
            ++ res;
            vis[i] = true;
        }
    }
    cout << res << endl;
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        memset(vis, false, sizeof(vis));
        scanf("%d", &n);
        scanf("%s%s", s[0] + 1, s[1] + 1);
        solve();
    }
    return 0;
}