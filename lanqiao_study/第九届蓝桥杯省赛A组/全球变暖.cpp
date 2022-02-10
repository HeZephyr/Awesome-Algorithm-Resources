/**
  *@filename:全球变暖
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-07 20:36
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000 + 5;
const int mod = 1e9+7;

int n;
string graph[maxn];
int go[][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool vis[maxn][maxn];//vis[i][j]表示该陆地像素是否已经被访问。
bool flag;//标志变量，判断岛是否被淹。
void dfs(int x,int y){
    //判断连通的像素。
    vis[x][y]=true;
    //cout<<x<<" "<<y<<endl;
    if(graph[x-1][y]=='#'&&graph[x+1][y]=='#'&&graph[x][y-1]=='#'&&graph[x][y+1]=='#'){
        flag=false;//说明该岛不会被淹。
    }
    for(int i=0;i<4;i++){
        int tx=x+go[i][0],ty=y+go[i][1];
        if(graph[tx][ty]=='#'&&!vis[tx][ty]){
            dfs(tx,ty);
        }
    }
}
void solve(){
    int cnt=0;
    memset(vis,false,sizeof(vis));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]=='#'&&!vis[i][j]){
                flag=true;
                dfs(i,j);
                if(flag)cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}
int main(){
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>graph[i];
        }
        solve();
    }
    return 0;
}