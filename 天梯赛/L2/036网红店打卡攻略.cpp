/**
  *@filename:036网红店打卡攻略
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-22 21:45
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 200 + 5;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;

int n,m,k;//n为网红点个数，m为网红店之间通路的条数。k为待检验的攻略数量。
int u,v,w;
int g[maxn][maxn];
int vis[maxn];//vis[i]标记访问过几次。
void solve(){
}
int main(){
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            g[i][j]=inf;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        g[u][v]=g[v][u]=w;
    }
    cin>>k;
    int minn=inf,pos;
    int temp,cur,x;
    int cnt=0;
    for(int i=1;i<=k;i++){
        int kk;
        cin>>kk;
        cur=0,temp=0;
        bool flag=false;
        memset(vis,0,sizeof(vis));
        for(int j=1;j<=kk;j++){
            cin>>x;
            if(g[cur][x]!=inf&&!vis[x]){
                temp+=g[cur][x];
                cur=x;
                vis[x]++;
            }
            else{
                flag=true;
            }
        }
        for(int j=1;j<=n;j++){
            if(vis[j]!=1){
                flag=true;
                break;
            }
        }
        if(!flag&&g[cur][0]!=inf){
            temp+=g[cur][0];
            //cout<<"temp:"<<temp<<endl;
            cnt++;
            if(temp<minn){
                minn=temp;
                pos=i;
            }
        }
    }
    cout<<cnt<<endl;
    cout<<pos<<" "<<minn<<endl;
    solve();
    return 0;
}