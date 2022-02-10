/**
  *@filename:方格分割
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-27 08:46
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int go[][2]={1,0,-1,0,0,1,0,-1};
bool vis[7][7];
//我们沿着点进行分割即可。由于存在着堆成，所以我们对最后的结果必须除以4.
int ans;
void dfs(int x,int y){
    if(x==0||y==0||x==6||y==6){
        ans++;
        return;
    }
    for(int i=0;i<4;i++){
        int tx=x+go[i][0];
        int ty=y+go[i][1];
        //将对称点也需要标记上。
        if(vis[tx][ty])continue;
        vis[tx][ty]=vis[6-tx][6-ty]=true;
        dfs(tx,ty);
        vis[tx][ty]=vis[6-tx][6-ty]=false;
    }
}
void solve(){
    memset(vis,false,sizeof(vis));
    vis[3][3]=true;
    ans=0;
    dfs(3,3);
    cout<<ans/4<<endl;
}
int main() {
    solve();
    return 0;
}