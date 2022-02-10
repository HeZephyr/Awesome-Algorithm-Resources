/**
  *@filename:第九题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-14 09:13
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,m,t,k;
struct node{
    int x,y;
    int t;//表示时间。
    node operator=(const node A){
        this->x=A.x,this->y=A.y,this->t=A.t;
        return *this;
    }
};
queue<node> q;
bool a[105][105];
int go[4][2]={0,1,0,-1,1,0,-1,0};
node head,temp;
void bfs(){
    int ans=0;
    //入队的都是已经被灌溉的，我们统计有多少点入队了即可。
    while(!q.empty()){
        head=q.front();
        ans++;
        q.pop();
        if(head.t>=k)continue;
        for(int i=0;i<4;i++){
            temp.x=head.x+go[i][0],temp.y=head.y+go[i][1];
            if(temp.x<1||temp.x>n||temp.y<1||temp.y>m||a[temp.x][temp.y])continue;
            a[temp.x][temp.y]=true;
            temp.t=head.t+1;
            q.push(temp);
        }
    }
    cout<<ans<<endl;
}
void solve(){
    bfs();
}
int main(){
    while(cin>>n>>m){
        cin>>t;
        while(!q.empty())q.pop();
        memset(a,0,sizeof(a));
        int x,y;
        for(int i=0;i<t;i++){
            cin>>x>>y;
            a[x][y]=true;
            temp.x=x,temp.y=y,temp.t=0;
            q.push(temp);
        }
        cin>>k;
        solve();
    }
    return 0;
}