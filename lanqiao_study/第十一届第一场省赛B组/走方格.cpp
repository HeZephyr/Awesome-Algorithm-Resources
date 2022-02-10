/**
  *@filename:走方格
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 19:09
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,m;
int f[35][35];//f[i][j]表示从(1,1)到(i,j)这个格子的方案集合。
void solve(){
    f[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1)continue;
            if(i%2==0&&j%2==0)f[i][j]=0;
            else f[i][j]=f[i-1][j]+f[i][j-1];
        }
    }
    cout<<f[n][m]<<endl;
}
int main(){
    while(cin>>n>>m){
        solve();
    }
    return 0;
}