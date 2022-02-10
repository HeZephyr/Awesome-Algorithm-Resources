/**
  *@filename:棋盘分割
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-18 15:59
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 9,M = 16;
const int P = 1e9+7;

int n,m=8;
double f[N][N][N][N][M];//其中f[x1][y1][x2][y2]：左上角为(x1,y1)，右下角为(x2,y2)的子矩阵，分割k次的集合。
//我们这种切割方法自然有4中情况。对于横切，我们可以选择上半部分，也可以选择下半部分。纵切同理。
//横切取上半部分，则dp[x1][y1][x2][y2]=min(dp[x1][y1][i][y2]+get(i+1,y1,x2,y2))
//横切取下半部分，则dp[x1][y1][x2][y2]=min(dp[i+1][y1][x2][y2]+get(x1,y1,i,y2));
//其中x1<=i<=x2
//那么纵切就同理了。
//纵切取左半部分，则dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][j]+get(x1,j+1,x2,y2));
//纵切取右半部分，则dp[x1][y1][x2][y2]=min(dp[x1][j+1][x2][y2]+get(x1,y1,x2,j));
//确定了这些，这个题实际上就好做了。
//利用前缀和公式和面积计算。利用get函数求前缀和。
double s[N][N];//其中s[x1][y1]=s[x1-1][y1]+s[x1][y1-1]-s[x1-1][y1-1]+a[i][j];
double X;//定义一个均值。
double get(int x1,int y1,int x2,int y2){
    double ans=s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]-X;
    return ans*ans;
}
double dp(int x1,int y1,int x2,int y2,int k){
    double &ans = f[x1][y1][x2][y2][k];
    if(ans>=0){
        //说明已经初始划过。
        return ans;
    }
    if(k==1){
        //说明已经分到最后一个了。
        return ans = get(x1,y1,x2,y2);
    }
    //否则就开始模拟判断。
    ans = 0x3f3f3f3f;//求最小值需初始化ans
    //横着切。
    for(int i = x1; i < x2; i++){
        ans = min(ans,dp(x1,y1,i,y2,k-1)+get(i+1,y1,x2,y2));
        ans = min(ans,dp(i+1,y1,x2,y2,k-1)+get(x1,y1,i,y2));
    }
    //竖着切。
    for(int i = y1; i < y2; i++){
        ans = min(ans,dp(x1,y1,x2,i,k-1)+get(x1,i+1,x2,y2));
        ans = min(ans,dp(x1,i+1,x2,y2,k-1)+get(x1,y1,x2,i));
    }
    return ans;
}
void solve(){
    X = s[m][m]/n;//求出均值。
    memset(f,-1,sizeof(f));
    //开始递归去计算。
    printf("%.3lf\n",sqrt(dp(1,1,m,m,n)/n));
}
int main(){
    cin>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cin>>s[i][j];
            s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];//求前缀和，即面积。
        }
    }
    solve();
    return 0;
}