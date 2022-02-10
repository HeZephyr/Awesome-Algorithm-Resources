/**
  *@filename:旋转
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 01:11
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100 + 5;
const int mod = 1e9+7;

int n,m;
int a[maxn][maxn];
int b[maxn][maxn];
void solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[j][n-i+1]=a[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout<<b[i][j];
            j==n?cout<<endl:cout<<" ";
        }
    }
}
int main(){
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        solve();
    }
    return 0;
}