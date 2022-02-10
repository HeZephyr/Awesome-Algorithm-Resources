#include<bits/stdc++.h>

using namespace std;

const int maxn=1010;
int n,m;
string s[maxn];
int dp[maxn][maxn];
string op;
int maxx;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>s[i];
    int len1,len2,cnt;
    while(m--){
        cin>>op>>maxx;
        cnt=0,len2=op.size();
        for(int t=0;t<n;t++){
            len1=s[t].size();
            for(int i=0;i<=len1;i++)dp[i][0]=i;
            for(int j=0;j<=len2;j++)dp[0][j]=j;
            for(int i=1;i<=len1;i++){
                for(int j=1;j<=len2;j++){
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(s[t][i-1]!=op[j-1]));
                }
            }
            if(maxx>=dp[len1][len2])cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}