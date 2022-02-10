/**
  *@filename:E.数塔
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-14 10:30
**/
#include<stdio.h>
#include<string.h>

int dp[105][105];
int c,n;//n为数塔高度。
int max(int a,int b){
    //求两数之间最大值。
    return a>b?a:b;
}
void solve(){
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            dp[i][j]=dp[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    printf("%d\n",dp[1][1]);
}
int main(){
    while(scanf("%d",&c)!=EOF){
        while(c--){
            scanf("%d",&n);
            for(int i=1;i<=n;i++){
                for(int j=1;j<=i;j++){
                    scanf("%d",&dp[i][j]);
                }
            }
            solve();
        }
    }
    return 0;
}