/**
  *@filename:滑雪
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-04 13:21
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 300 + 5;
const int P = 1e9+7;

//记忆化搜索即是保留已经找到的结果，从这点出发的最佳选择。
int n,m,a[N][N];
int go[4][2] = {0,1,0,-1,1,0,-1,0};
int f[N][N];//f[i][j]表示从f[i][j]出发滑行的最远距离。
int dfs(int x,int y){
    if(f[x][y]){
        //说明已经被确定。
        return f[x][y];
    }
    for(int i = 0; i < 4; ++ i){
        int temp_x = x + go[i][0],temp_y = y + go[i][1];
        if(temp_x >= 1 && temp_x <= n && temp_y >= 1 && temp_y <= m && a[temp_x][temp_y] < a[x][y]){
            f[x][y] = max(f[x][y],dfs(temp_x,temp_y) + 1);
        }
    }
    return f[x][y];
}
void solve(){
    int maxx  = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            maxx = max(maxx,dfs(i,j));
        }
    }
    printf("%d\n",maxx + 1);//加上自己。
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            scanf("%d", &a[i][j]);
        }
    }
    solve();
    return 0;
}