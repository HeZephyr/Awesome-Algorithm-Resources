/**
  *@filename:红色警报
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-20 20:12
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 50000 + 5;
const int mod = 1e9+7;

int n,m,k;
struct Edge{
    int u,v;
}edges[maxn];
int father[maxn],info[maxn];
bool vis[maxn];
int find(int x){
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
void work(){
    for(int i=0;i<n;i++)father[i]=i;
    int fu,fv;
    for(int i=0;i<m;i++){
        if(vis[edges[i].u]||vis[edges[i].v])continue;
        fu=find(edges[i].u),fv=find(edges[i].v);
        if(fu!=fv)father[fu]=fv;
    }
}
int Count(){
    int ans=0;
    for(int i=0;i<n;i++){
        if(!vis[i]&&father[i]==i){
            ans++;
        }
    }
    return ans;
}
void solve(){
    work();
    int pre_cnt=Count(),cur_cnt;
    for(int t=0;t<k;t++){
        vis[info[t]]=true;
        work();
        bool flag=false;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                flag=true;
                break;
            }
        }
        cur_cnt=Count();
        if(cur_cnt>pre_cnt)printf("Red Alert: City %d is lost!\n",info[t]);
        else printf("City %d is lost.\n",info[t]);
        if(!flag){ 
            puts("Game Over.");
            continue;
        }
        pre_cnt=cur_cnt;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)father[i]=i;
    int u,v;
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        edges[i].u=u,edges[i].v=v;
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++)scanf("%d",&info[i]);
    solve();
    return 0;
}