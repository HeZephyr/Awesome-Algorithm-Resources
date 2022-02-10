/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-03 14:02
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,m,k,x,y;
int g[55][55];
int result[55][55];
int get_max(int x,int y){
    int maxx=0;
    for(int i=x;i<x+k&&i<=n;i++){
        for(int j=y;j<y+k&&j<=m;j++){
            maxx=max(maxx,g[i][j]);
        }
    }
    return maxx;
}
void solve(){
    for(int i=1;i<=n-k+1;i++){
        for(int j=1;j<=m-k+1;j++){
            result[i][j]=get_max(i,j);
        }
    }
    cout<<n-k+1<<" "<<m-k+1<<endl;
    for(int i=1;i<=n-k+1;i++){
        for(int j=1;j<=m-k+1;j++){
            cout<<result[i][j];
            j==m-k+1?cout<<endl:cout<<" ";
        }
    }
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    solve();
    return 0;
}