/**
  *@filename:迷宫
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-11 22:00
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 50 + 5;
const int mod = 1e9+7;

struct node{
    int x,y;
    int step;
    string path;//记录路径。
    node operator=(const node A){
        this->x=A.x,this->y=A.y,this->step=A.step;
        this->path=A.path;
        return *this;
    }
};
char s[maxn][maxn];//由于要求最少步数，所以我们可以利用bfs搜索。
string goInfo[]={"D","L","R","U"};//根据字典序来抉择。
bool vis[55][55];//判断点是否被访问。
int  go[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
void bfs(){
    queue<node> q;
    node head,temp;
    temp.x=0,temp.y=0,temp.step=0;
    vis[temp.x][temp.y]=true;
    q.push(temp);
    while(!q.empty()){
        head=q.front();
        q.pop();
        if(head.x==29&&head.y==49){
            cout<<head.step<<endl;
            cout<<head.path<<endl;
        }
        for(int i=0;i<4;i++){
            temp.x=head.x+go[i][0],temp.y=head.y+go[i][1];
            if(temp.x<0||temp.x>=30||temp.y<0||temp.y>=50)continue;
            if(s[temp.x][temp.y]=='1'||vis[temp.x][temp.y])continue;
            temp.path=head.path,temp.step=head.step+1;
            vis[temp.x][temp.y]=true;
            temp.path=head.path+goInfo[i];
            q.push(temp);
        }
    }
}
void solve(){
    memset(vis,false,sizeof(vis));
    bfs();
}
int main(){
    for(int i=0;i<30;i++){
        cin>>s[i];
    }
    solve();
    return 0;
}