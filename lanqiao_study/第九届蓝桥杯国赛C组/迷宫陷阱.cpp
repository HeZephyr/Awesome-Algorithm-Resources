/**
  *@filename:迷宫陷阱
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-15 20:39
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000 + 5;
const int P = 1e9+7;
const int INF = 0x3f3f3f3f;

int n,k;
char g[N][N];
bool vis[N][N][11];
struct node{
    int x,y;
    int last;//保存这个点的无敌状态持续时间。
    int step;
};
int go[4][2]={0,1,0,-1,1,0,-1,0};
void bfs(){
    node head,temp;
    queue<node> q;
    head.x=1,head.y=1,head.step=0,head.last=0;
    q.push(head);
    bool flag=false;
    memset(vis,0,sizeof(vis));
    vis[1][1][0]=true;
    int minn=INF;
    while(!q.empty()){
        head=q.front();
        q.pop();
        if(head.x==n&&head.y==n){
            minn=head.step;
            break;
        }
        for(int i=0;i<4;i++){
            temp.x=head.x+go[i][0],temp.y=head.y+go[i][1];
            if(temp.x>=1&&temp.x<=n&&temp.y>=1&&temp.y<=n&&g[temp.x][temp.y]!='#'){
                if(g[temp.x][temp.y]=='%'&&vis[temp.x][temp.y][k]==0){
                    vis[temp.x][temp.y][k]=1;
                    temp.last=k,temp.step=head.step+1;
                    q.push(temp);
                }
                else{
                    if(g[temp.x][temp.y]!='#'&&head.last>0&&vis[temp.x][temp.y][head.last-1]==0){
                        vis[temp.x][temp.y][head.last-1]=1;
                        temp.last=head.last-1,temp.step=head.step+1;
                        q.push(temp);
                    }
                    else if(g[temp.x][temp.y]=='.'&&head.last==0&&vis[temp.x][temp.y][0]==0){
                        vis[temp.x][temp.y][0]=1;
                        temp.last=0,temp.step=head.step+1;
                        q.push(temp);
                    }
                }
            }
        }  
    }
    if(minn==INF)minn=-1;
    cout<<minn<<endl;
}
void solve(){
    bfs();
}
int main(){
    while(cin>>n>>k){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>g[i][j];
            }
        }
        solve();
    }
    return 0;
}