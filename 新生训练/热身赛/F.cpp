#include<bits/stdc++.h>

using namespace std;

const int maxn=2e3+2;
const int mod=1e3;
int t,n;
int dp[maxn][maxn];//dp[i][j]表示i个人分j个集合的方法
int result[maxn];
void init(){
    dp[1][1]=1;//初始状态，当只有1个人的时候只能分一个集合。
    result[1]=1;
    for(int i=2;i<=2000;i++){
        dp[i][1]=1,dp[i][i]=1;
        result[i]=2;//至少存在以上两种情况。
        for(int j=2;j<i;j++){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*j;
            dp[i][j]%=1000;
            result[i]+=dp[i][j];
        }
        result[i]%=1000;
    }
}
void solve(){
}
int main(){
    init();
    while(cin>>t){
        while(t--){
            cin>>n;
            cout<<result[n]<<endl;
        }
    }
    return 0;
}