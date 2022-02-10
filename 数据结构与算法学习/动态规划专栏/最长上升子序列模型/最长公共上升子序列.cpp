#include<bits/stdc++.h>

using namespace std;

const int maxn=3010;
int n;
int a[maxn],b[maxn];
int dp[maxn][maxn];//dp[i][j]表示A中的前i个和B中的前j个，且以b[j]结尾的最长上升公共子序列。

/* //朴素做法。
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j];
            //若包含a[i]，即a[i]和b[j]相等。
            if(a[i]==b[j]){
                int maxx=1;
                //求b[1]->b[j-1]中的最大值。
                for(int k=1;k<j;k++){
                    if(b[k]<b[j]){
                        maxx=max(maxx,dp[i-1][k]+1);
                    }
                }
                dp[i][j]=max(maxx,dp[i][j]);
            }
        }
    }
    int res=0;
    for(int j=1;j<=n;j++){
        res=max(res,dp[n][j]);
    }
    cout<<res<<endl;
    return 0;
} */
//优化做法，不需要比较这么多次。
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        int maxx=1;
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j];
            //若包含a[i]，即a[i]和b[j]相等。
            if(a[i]==b[j])dp[i][j]=max(dp[i][j],maxx);
            if(a[i]>b[j]){
                maxx=max(maxx,dp[i-1][j]+1);
            }
        }
    }
    int res=0;
    for(int j=1;j<=n;j++){
        res=max(res,dp[n][j]);
    }
    cout<<res<<endl;
    return 0;
}
