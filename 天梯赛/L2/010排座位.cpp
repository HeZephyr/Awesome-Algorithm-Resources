/**
  *@filename:010排座位
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-20 18:50
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100 + 5;
const int mod = 1e9+7;

int n,m,k;//宾客总人数、关系数、查询的条数。
int enemy[maxn][maxn];
int father[maxn];
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
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy)father[fx]=fy;
}
void solve(){
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)father[i]=i;
    int x,y,op;
    while(m--){
        cin>>x>>y>>op;
        if(op==1){
            merge(x,y);
        }
        else{
            enemy[x][y]=enemy[y][x]=1;
        }
    }
    while(k--){
        cin>>x>>y;
        if(find(x)==find(y)&&!enemy[x][y]){
            puts("No problem");
        }
        else if(find(x)!=find(y)&&!enemy[x][y]){
            puts("OK");
        }
        else if(find(x)==find(y)&&enemy[x][y]){
            puts("OK but...");
        }
        else if(enemy[x][y]){
            puts("No way");
        }
    }
    solve();
    return 0;
}