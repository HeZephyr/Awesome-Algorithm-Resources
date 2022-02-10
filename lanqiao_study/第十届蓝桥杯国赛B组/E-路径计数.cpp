/**
  *@filename:E-路径计数
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-04 19:55
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 10;
const int P = 1e9+7;

bool vis[N][N];
int ans;//记录方案数。
int go[4][2] = {1,0,-1,0,0,1,0,-1};
void dfs(int x,int y,int step){
    //x和y代表当前坐标，step代表走到当前的长度。
    if(step > 12){
        return;
    }
    if(!x && !y && step >= 4 && step <= 12){
        ans ++;
    }
    for(int i = 0; i < 4; ++ i){
        int dx = x + go[i][0],dy = y + go[i][1];
        if(dx < 0 || dx > 5 || dy < 0 || dy > 5 || vis[dx][dy]){
            continue;
        }
        vis[dx][dy] = true;
        dfs(dx,dy,step + 1);
        vis[dx][dy] = false;
    }
}
void solve(){
    dfs(0,0,0);
    printf("%d\n",ans);
}
int main(){
    solve();
    return 0;
}