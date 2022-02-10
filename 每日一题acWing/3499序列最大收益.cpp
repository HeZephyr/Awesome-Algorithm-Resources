#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 200 + 5;
const int mod = 1e9+7;

int n,k,m;
int a[maxn];
int w[maxn][maxn];
int f[maxn][maxn];//f[i][j]表示只考虑前i个数共删除了j个数且保留了第i个数的方案的最大收益。
//f(k,j-(i-k-1)+)+w(ak,ai)
void solve(){
    memset(f,-0x3f,sizeof(f));//初始化f数组。
    f[1][0]=0;
    for(int i=2;i<=m;i++){
        for(int j=0;j<=k;j++){
            for(int u=1;u<i;u++){
                if(j>=i-u-1){
                    f[i][j]=max(f[i][j],f[u][j-(i-u-1)]+w[a[u]][a[i]]);
                }
            }
        }
    }
    int maxx=0;
    for(int i=0;i<=k;i++){
        maxx=max(f[m][i],maxx);
    }
    cout<<maxx<<endl;
}
int main(){
    cin>>n>>k>>m;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>w[i][j];
        }
    }
    solve();
    return 0;
}