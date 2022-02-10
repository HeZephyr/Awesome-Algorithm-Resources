#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn=1e5+10;

struct Edge{
    int u,v,w;
    bool operator<(const Edge A){
        return w<A.w;//运算符重载。
    }
};
int n,m;//n个顶点m条边。
int father[maxn];//连通块。
Edge edges[maxn];//边集合。
int Find(int x){
    int r=x;
    while(r!=father[r])r=father[r];
    int i=x,j;
    while(father[i]!=r){
        j=father[i];
        father[i]=r;
        i=j;
    }
    return r;
}
void Kruskal(){
    sort(edges,edges+m);
    for(int k=1;k<=n;k++)father[k]=k;
    int fu,fv;
    int ans=0;
    for(int i=0;i<m;i++){
        fu=Find(edges[i].u),fv=Find(edges[i].v);
        if(fu!=fv){
            father[fu]=fv;
            ans=max(ans,edges[i].w);
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(father[i]==i)cnt++;
    }
    if(cnt>1){
        cout<<"The graph isn't get the minest tree!"<<endl;
    }
    else{
        cout<<ans<<endl;
    }
}
int main(){
    while(cin>>n>>m){
        int u,v,w;
        for(int i=0;i<m;i++){
            cin>>u>>v>>w;
            //最小生成树以无向图为例。一般都是无向图。
            edges[i].u=u,edges[i].v=v,edges[i].w=w;
        }
        Kruskal(); 
    }
    return 0;
}