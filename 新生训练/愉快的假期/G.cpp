#include<bits/stdc++.h>

using namespace std;

const int maxn=1e2+5;
const int inf=1e6;

int n,m;
int graph[maxn][maxn];//无向图。
int dis[maxn][maxn];//dis[i][j]表示i到j的最短路径。
int minn;
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<k;i++){
            for(int j=i+1;j<k;j++){
                minn=min(minn,dis[i][j]+graph[j][k]+graph[k][i]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
int main(){
    while(cin>>n>>m){
        //初始化
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                dis[i][j]=dis[j][i]=graph[i][j]=graph[j][i]=inf;
            }
        }
        minn=inf;
        int u,v,w;
        for(int i=0;i<m;i++){
            cin>>u>>v>>w;
            if(w<graph[u][v])graph[u][v]=graph[v][u]=dis[u][v]=dis[v][u]=w;
        }
        floyd();
        if(minn==inf)cout<<"It's impossible.\n";
        else cout<<minn<<endl;
    }
    return 0;
}