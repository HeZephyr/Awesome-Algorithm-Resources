/**
  *@filename:迷宫
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-26 10:19
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//我们可以dfs每个点。
bool vis[11][11];//判断该点是否已经访问。
string graph[11];
bool flag;//判断是否已经逃出迷宫。
void dfs(int x,int y){
    if(x<0||x>=10||y<0||y>=10){
        flag=true;
        return;
    }
    vis[x][y]=true;
    if(graph[x][y]=='L'&&!vis[x][y-1]){
        dfs(x,y-1);
    }
    else if(graph[x][y]=='R'&&!vis[x][y+1]){
        dfs(x,y+1);
    }
    else if(graph[x][y]=='U'&&!vis[x-1][y]){
        dfs(x-1,y);
    }
    else if(graph[x][y]=='D'&&!vis[x+1][y]){
        dfs(x+1,y);
    }
}
void solve(){
    int ans=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            memset(vis,false,sizeof(vis));
            flag=false;
            dfs(i,j);
            if(flag)ans++;
        }
    }
    cout<<ans<<endl;
}
int main() {
    for(int i=0;i<10;i++){
        cin>>graph[i];
    }
    solve();
    return 0;
}