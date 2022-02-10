/**
  *@filename:POJ1179
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-16 14:56
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5;
const int P = 1e9+7;
const int INF = 0x3f3f;
int n;
int dp[N][N][2],num[N];
//其中dp[l][r][0]表示从第l个顶点到第r个顶点合成的最大值是多少。
//dp[l][r][1]表示从第l个顶点到第r个顶点合成的最小值是多少。
//由于此题是环形，所以为了拆分出来，我们需要加长倍数边长线性结构。
char op[N];
void solve(){
    //初始化。对于1~n合成的值就为之间的运算值。
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            dp[i][j][0]=-INF;
            dp[i][j][1]=INF;
        }
    }
    for(int i=1;i<=2*n;i++){
        dp[i][i][0]=num[i];
        dp[i][i][1]=num[i];
    }
    //枚举区间长度和区间起点。
    for(int len=1;len<=n;len++){
        for(int l=1;l+len<=2*n;l++){
            int r=l+len;
            //枚举分割点。
            for(int k=l;k<r;k++){
                //根据分割点求，要知道最大值来自最大值*最大值或最大值+最大值或者最小值*最小值。
                if(op[k+1]=='t'){
                    //加法。
                    dp[l][r][0]=max(dp[l][r][0],dp[l][k][0]+dp[k+1][r][0]);
                    dp[l][r][1]=min(dp[l][r][1],dp[l][k][1]+dp[k+1][r][1]);
                }
                else{
                    //乘法。我们需要最大值的来源。
                    dp[l][r][0]=max(dp[l][r][0],dp[l][k][0]*dp[k+1][r][0]);
                    dp[l][r][0]=max(dp[l][r][0],dp[l][k][1]*dp[k+1][r][1]);
                    dp[l][r][1]=min(dp[l][r][1],dp[l][k][1]*dp[k+1][r][1]);
                    dp[l][r][1]=min(dp[l][r][1],dp[l][k][0]*dp[k+1][r][1]);
                    dp[l][r][1]=min(dp[l][r][1],dp[l][k][1]*dp[k+1][r][0]);
                }
                //cout<<l<<" "<<r<<" "<<endl;
                //cout<<"maxx:"<<dp[l][r][0]<<" minn"<<dp[l][r][1]<<endl;
            }
        }
    }
    int maxx=-13847;
    for(int i=1;i<=n;i++)maxx=max(maxx,dp[i][i+n-1][0]);
    cout<<maxx<<endl;
    for(int i=1;i<=n;i++){
        if(dp[i][i+n-1][0]==maxx){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>op[i]>>num[i];
        op[i+n]=op[i];
        num[i+n]=num[i];
    }
    solve();
    return 0;
}