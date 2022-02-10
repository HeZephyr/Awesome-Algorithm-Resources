/**
  *@filename:D
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-30 16:51
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int N = 500 + 5;
const int P = 1e9+7;

struct node{
    int x,y,z;
    //注意自定义优先队列排序的一些细节。
    bool operator < (const node &A) const {
        return z < A.z;
    }
}nodes[N];
int n,m;//网格的高度和宽度。
bool p[N][N];//判断(i,j)是否已经被确定。
priority_queue<node> q;
int a[N][N];
int go[4][2] = {0,1,0,-1,1,0,-1,0};
void dfs(int x,int y){
    p[x][y] = 1;
    for(int i = 0; i < 4; ++ i){
        int dx = x + go[i][0],dy = y + go[i][1];
        if(dx >= 1 && dx <= n && dy >= 1 && dy <= m && a[dx][dy] <= a[x][y] && !p[dx][dy]){
            dfs(dx,dy);
        }
    }
}
void solve(){
    int ans = 0;
    while(!q.empty()){
        node head = q.top();
        q.pop();
        if(!p[head.x][head.y]){
            //开始遍历。
            dfs(head.x,head.y);
            ans ++;
        }
    }
    printf("%d\n", ans);
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            scanf("%d", &a[i][j]);
            if(a[i][j] <= 1){
                p[i][j] = 1;
            }
            else{
                p[i][j] = 0;
                q.push({i,j,a[i][j]});
            }
        }
    }
    solve();
    return 0;
}