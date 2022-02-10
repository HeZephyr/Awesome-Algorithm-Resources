/**
  *@filename:G_To_Go_Or_Not_To_Go_
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-06 21:45
**/
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 2000 + 5;
const int mod = 1e9+7;
const ll inf = 0x3f3f3f3f3f3f3f;

int n,m,w;
ll dist1[maxn][maxn],dist2[maxn][maxn];//dist1[i][j]表示(1,1)到(i,j)的最短路径，dist2[i][j]表示(n,m)到(i,j)的最短路径。
int g[maxn][maxn];//图。
int go[4][2]={0,1,1,0,0,-1,-1,0};//行走路径。
void bfs(pii st,ll dist[maxn][maxn]){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dist[i][j]=inf;//初始化。
        }
    }
    queue<pii> q;
    dist[st.x][st.y]=0;
    pii head,temp;
    q.push(st);
    while(!q.empty()){
        head = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            temp.x=head.x+go[i][0],temp.y=head.y+go[i][1];
            if(temp.x>=1&&temp.x<=n&&temp.y>=1&&temp.y<=m&&g[temp.x][temp.y]!=-1&&dist[temp.x][temp.y]>dist[head.x][head.y]+w){
                dist[temp.x][temp.y]=dist[head.x][head.y]+w;
                q.push(temp);
            }
        }
    }
}
void solve(){
    bfs({1,1},dist1);
    bfs({n,m},dist2);
    ll minn1=inf,minn2=inf;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //穿插使用传送门，优化最小值。
            if(g[i][j]<=0)continue;
            minn1=min(minn1,dist1[i][j]+g[i][j]);
            minn2=min(minn2,dist2[i][j]+g[i][j]);
            //cout<<minn1<<" "<<minn2<<endl;
        }
    }
    ll ans=min(minn1+minn2,dist1[n][m]);
    if(ans>=inf)ans=-1;
    printf("%lld\n",ans);//注意是lld
}
int main(){
    scanf("%d%d%d",&n,&m,&w);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&g[i][j]);
        }
    }
    solve();
    return 0;
}