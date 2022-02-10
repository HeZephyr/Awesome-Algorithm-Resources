#include<bits/stdc++.h>

using namespace std;

const int maxn=1e3+10;
char a[maxn],b[maxn];
int len_a,len_b;
int dp[maxn][maxn];
int main(){
    cin>>len_a>>len_b>>a+1>>b+1;
    for(int i=1;i<=len_a;i++){
        for(int j=1;j<=len_b;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//状态转移。
            if(a[i]==b[j]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    cout<<dp[len_a][len_b]<<endl;
    return 0;
}