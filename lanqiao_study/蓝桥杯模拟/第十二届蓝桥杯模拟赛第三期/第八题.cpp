/**
  *@filename:第八题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-14 08:54
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,m;
int a[105][105],b[105][105];
int go[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
void solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int tx,ty;
            for(int k=0;k<8;k++){
                tx=i+go[k][0],ty=j+go[k][1];
                if(tx>=1&&tx<=n&&ty>=1&&ty<=m){
                    b[i][j]=max(b[i][j],a[tx][ty]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<b[i][j];
            j==m?cout<<endl:cout<<" ";
        }
    }
}
int main(){
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                b[i][j]=a[i][j];
            }
        }
        solve();
    }
    return 0;
}