#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=1e5+10;
//对边进行排序。
int n,m;
struct Edge{
    int u,v;
    long long pay;
    //u,v以及边权值。
    bool operator<(const Edge A){
        return pay<A.pay;
    }
};
Edge edges[maxn];
int father[5005];
int find(int x){
    int r=x;
    while(r!=father[r]){
        r=father[r];
    }
    return r;
}
void solve(){
    sort(edges,edges+m);
    int fu,fv;
    int i;
    for(i=1;i<=n;i++)father[i]=i;
    i=0;
    bool flag=false;
    long long ans=0;
    while(i<m){
        fu=find(edges[i].u),fv=find(edges[i].v);
        if(fu!=fv){
            ans=max(ans,edges[i].pay);
            father[fu]=fv;
        }
        int temp=0;
        for(int i=1;i<=n;i++){
            if(father[i]==i)temp++;
        }
        if(temp==1){
            flag=true;
            break;
        }
        i++;
    }
    if(flag){
        cout<<ans<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}
int main(){
    while(cin>>n>>m){
        int u,v,w;
        for(int i=0;i<m;i++){
            cin>>u>>v>>w;
            edges[i].u=u,edges[i].v=v,edges[i].pay=w;
        }
        solve();
    }
    return 0;
}