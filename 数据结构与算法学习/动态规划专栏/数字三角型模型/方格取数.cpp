/**
  *@filename:方格取数
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-19 20:13
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 10 + 5;
const int P = 1e9+7;

int n,a[N][N];
int f[N*2][N][N];//其中f[k][x1][x2]表示从(1,1)走到(x1,k-x1)和(x2,k-x2)的最大和。
//则我们即可得到状态转移方程。枚举即可。
void solve(){
    for(int k=2;k<=2*n;k++){
        for(int x1=1;x1<=n;x1++){
            for(int x2=1;x2<=n;x2++){
                int y1=k-x1,y2=k-x2;
                //判断是否越界。
                if(y1>=1&&y1<=n&&y2>=1&&y2<=n){
                    int &ans=f[k][x1][x2];
                    int t=a[x1][y1];
                    if(x1!=x2)t+=a[x2][y2];
                    ans=max(ans,f[k-1][x1-1][x2-1]+t);
                    ans=max(ans,f[k-1][x1-1][x2]+t);
                    ans=max(ans,f[k-1][x1][x2-1]+t);
                    ans=max(ans,f[k-1][x1][x2]+t);
                }
            }
        }
    }
    cout<<f[2*n][n][n]<<endl;
}
int main(){
    cin>>n;
    int x,y,z;
    while(cin>>x>>y>>z&&(x||y||z))a[x][y]=z;
    solve();
    return 0;
}