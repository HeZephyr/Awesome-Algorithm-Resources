#include<iostream>

using namespace std;

const int maxn=1e3+5;
const int inf=0x3f3f3f3f;
int n,m;//n个顶点m条边。
int dist[maxn][maxn];//dist[i][j]表示的是i到j的最短路径。
int min(int a,int b){
    if(a<b)return a;
    else return b;
}
void Floyd(){
    //不断插入中间顶点去更新。
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(dist[i][k]==inf)continue;//跳过不存在的边。
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}
void Print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]>=inf?printf("%d->%d isn't arrive!\n",i,j):printf("%d->%d,The minest distance is %d\n",i,j,dist[i][j]);
        }
    }
}
int main(){
    while(cin>>n>>m){
        int u,v,w;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=inf;
            }
        }
        for(int i=0;i<m;i++){
            //这里以有向图为例。
            cin>>u>>v>>w;//这表示的是u->v的边权值。
            dist[u][v]=w;
        }
        Floyd();
        Print();
    }
    return 0;
}
/* 
3 3
1 2 5
2 3 5
3 1 2 
*/