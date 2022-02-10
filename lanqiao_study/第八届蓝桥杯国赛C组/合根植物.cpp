/**
  *@filename:合根植物
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-07 20:38
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000000 + 5;
const int mod = 1e9+7;

int n,m,k,father[maxn];
int u,v;
void solve(){
}
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
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n*m;i++)father[i]=i;
    for(int i=1;i<=k;i++){
        cin>>u>>v;
        u=find(u),v=find(v);
        if(u!=v){
            father[u]=v;
        }
    }
    int cnt=0;
    for(int i=1;i<=n*m;i++){
        if(father[i]==i)cnt++;
    }
    cout<<cnt<<endl;
    solve();
    return 0;
}