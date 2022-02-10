/**
  *@filename:传纸条
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-19 20:56
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 55 + 5;
const int P = 1e9+7;

int n,m,a[N][N];
int f[N*2][N][N];//我们用f[k][x1][x2]表示从(1,1)走到(x1,k-x1)、(x2,k-x2)的好心程度的最大值。
void solve(){
    for(int k=2;k<=n+m;k++){
        for(int x1=1;x1<=n;x1++){
            for(int x2=1;x2<=n;x2++){
                int y1=k-x1,y2=k-x2;
                if(y1<1||y1>m||y2<1||y2>m)continue;
                int t=a[x1][y1];
                if(x1!=x2)t+=a[x2][y2];
                int &ans=f[k][x1][x2];
                ans=max(ans,f[k-1][x1-1][x2-1]+t);
                ans=max(ans,f[k-1][x1-1][x2]+t);
                ans=max(ans,f[k-1][x1][x2-1]+t);
                ans=max(ans,f[k-1][x1][x2]+t);
            }
        }
    }
    cout<<f[n+m][n][n]<<endl;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    solve();
    return 0;
}