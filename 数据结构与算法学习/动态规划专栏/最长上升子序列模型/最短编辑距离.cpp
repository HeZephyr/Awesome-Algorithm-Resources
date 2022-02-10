#include<bits/stdc++.h>

using namespace std;

const int maxn=1010;
int n,m;
char a[maxn],b[maxn];
int dp[maxn][maxn];//dp[i][j]表示的是将a的前i个字母变为b的前j个字母的最小操作次数。
//我们总共有四种操作，插入、删除、替换和什么也不做。
//对于插入来说，如果我们插入变为dp[i][j]，那么上一个状态就是dp[i][j-1]，我们插入一个使其相等。
//对于删除来说，如果我们删除变为dp[i][j]，那么上一个状态就是dp[i-1][j]。我们删除一个变为b
//对于替换来说，如果我们替换变为dp[i][j]，那么上一个状态就是dp[i-1][j-1]，我们替换让a[i]=b[j]，因为a[i]!=b[j]。
//对于什么也不做来说，如果我们什么也不做变为dp[i][j]，那么上个状态就是dp[i-1][j-1]，我们什么也不做，因为a[i]=b[j].

int main(){
    cin>>n>>a+1>>m>>b+1;
    for(int i=0;i<=n;i++)dp[i][0]=i;//一直删除。
    for(int j=0;j<=m;j++)dp[0][j]=j;//一直插入。
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=min(dp[i][j-1],dp[i-1][j])+1;//插入和删除中抉择最优。
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(a[i]!=b[j]));//要替换还是要删除。
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}