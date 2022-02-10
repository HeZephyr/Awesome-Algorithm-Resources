/**
  *@filename:C-拼接
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-04 17:16
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 10 + 5;
const int P = 1e9+7;

bool vis[N][N];
int ans;
int go[4][2] = {0,1,0,-1,1,0,-1,0};
void dfs(int x,int y){
    if(x == 0 || y == 7){
        ans ++;
        return;
    }
    for(int i = 0; i < 4; ++ i){
        int dx = x + go[i][0],dy = y + go[i][1];
        if(dx < 0 || dx > 7 || dy < 0 || dy > 7 || vis[dx][dy] || dx == dy)continue;
        vis[dx][dy] = true;
        dfs(dx,dy);
        vis[dx][dy] = false;
    }
}
void solve(){
    for(int i = 0; i <= 7; ++ i){
        memset(vis,0,sizeof(vis));
        dfs(i,i);
    }
    printf("%d\n",ans);//2443
}
int main(){
    solve();
    return 0;
}