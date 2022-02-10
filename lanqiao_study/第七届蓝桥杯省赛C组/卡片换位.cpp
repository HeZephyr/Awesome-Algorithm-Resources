/**
  *@filename:卡片换位
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-21 10:38
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

struct node{
    int x,y,step;//(x,y)表示坐标，step代表所移动步骤。
    string str;//代表当前地图。
};
int go[][2]={1,0,-1,0,0,1,0,-1};
map<string,int> p;
int sx,sy,ax,ay,bx,by;
string graph; 
void bfs(){
    p.clear();
    queue<node> q;
    node head,temp;
    head.x=sx,head.y=sy,head.step=0,head.str=graph;
    p[head.str]++;
    q.push(head);
    while(!q.empty()){
        head=q.front();
        q.pop();
        if(head.str[ax*3+ay]=='B'&&head.str[bx*3+by]=='A'){
            cout<<head.step<<endl;
            return;
        }
        for(int i=0;i<4;i++){
            temp.x=head.x+go[i][0],temp.y=head.y+go[i][1];
            if(temp.x<0||temp.x>=2||temp.y<0||temp.y>=3)continue;
            temp.str=head.str,temp.step=head.step+1;
            swap(temp.str[temp.x*3+temp.y],temp.str[head.x*3+head.y]);
            if(p[temp.str])continue;
            p[temp.str]++;
            q.push(temp);
        }
    }
}
void solve(){
    for(int i=0;i<6;i++){
        if(graph[i]==' '){
            sx=i/3;
            sy=i%3;
        }
        else if(graph[i]=='A'){
            ax=i/3;
            ay=i%3;
        }
        else if(graph[i]=='B'){
            bx=i/3;
            by=i%3;
        }
    }
    bfs();
}
int main() {
    string str1,str2;
    while(getline(cin,str1)){
        getline(cin,str2);
        graph=str1+str2;
        solve();
    }
    return 0;
}