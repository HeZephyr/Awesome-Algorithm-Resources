/**
  *@filename:网格路径
  *@author: pursuit
  *@created: 2021-08-07 14:09
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 10 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n;
char g[N][N];
bool vis[N][N];
int ans;
bool dfs(int x,int y){
    //cout << x << " " << y << endl;
    if(x == n - 1 && y == n - 1){
        ans ++;
        return true;
    }
    for(int i = 0; i < 2; ++ i){
        int dx = x,dy = y;
        if(i == 0){
            dy += 1;
        }
        else{
            dx += 1;
        }
        if(dx >= 0 && dx < n && dy >= 0 && dy < n && g[dx][dy] == '.' && (!vis[dx][dy] || (dx == n - 1 && dy == n - 1))){
            vis[dx][dy] = true;
            if(!dfs(dx,dy)){
                vis[dx][dy] = false;
            }
            else{
                return true;
            }
        }
    }
    return false;
}
void solve(){
    if(g[0][0] == '#' || g[n - 1][n - 1] == '#'){
        puts("0");
        return;
    }
    dfs(0,0);
    dfs(0,0);
    printf("%d\n", ans);
}
int main(){    
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        ans = 0;
        memset(vis,0,sizeof(vis));
        for(int i = 0; i < n; ++ i){
            scanf("%s", g[i]);
        }
        solve();
    }
    return 0;
}