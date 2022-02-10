#include<bits/stdc++.h>

using namespace std;


//区间dp常用模板。
/*
//先枚举区间长度。
for(int len=2;len<=n;len++){
    //再枚举区间左右端点。
    for(int i=1;i+len-1<=n;i++){
        int j=i+len-1;
        //枚举分割点。
        dp[i][j]=最值。
        for(int k=i;k<j;k++){
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+s[j]-s[i-1]);
        }
    }
}
*/
const int maxn=310;
int dp[maxn][maxn];//dp[i][j]表示的就是从i到j合并的最小代价。
int w[maxn];
int pre[maxn];//前缀和。
int n;//n堆石子。
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        pre[i]=pre[i-1]+w[i];
    }
    for(int i=1;i<=n;i++)dp[i][i]=0;//状态初始化。
    //枚举区间长度。
    for(int len=2;len<=n;len++){
        //接下来枚举区间左右端点。
        //枚举区间起点。
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;//区间终点。
            //枚举分割点。
            dp[i][j]=1e8;
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+pre[j]-pre[i-1]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}