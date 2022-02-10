/**
  *@filename:E
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-18 14:50
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 10000 + 5;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;

//最短路板子题。
int n;
int g[maxn][maxn];
int dist[maxn];
bool vis[maxn];
int gcd(int n,int m){
    return n%m?gcd(m,n%m):m;
}
void init(){
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(abs(i-j)<=21){
                g[i][j]=g[j][i]=i*j/gcd(i,j);
            }
            else{
                g[i][j]=g[j][i]=inf;
            }
        }
    }
}
void dijkstra(int st){
    for(int i=1;i<=n;i++){
        dist[i]=g[st][i];
    }
    vis[st]=true;
    for(int i=1;i<=n;i++){
        int minn=inf,index;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&dist[j]<minn){
                minn=dist[j];
                index=j;
            }
        }
        if(minn==inf)break;
        vis[index]=true;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&dist[j]>dist[index]+g[index][j]){
                dist[j]=dist[index]+g[index][j];
            }
        }
    }
    cout<<dist[n]<<endl;//n=2021 print:10266837
}
void solve(){
    init();
    dijkstra(1);
}
int main(){
    while(cin>>n){
        solve();
    }
    return 0;
}