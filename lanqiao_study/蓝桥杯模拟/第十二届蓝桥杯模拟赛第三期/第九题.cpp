/**
  *@filename:第九题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-14 15:09
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,m;
int dp[1005][1005];
int sum;
void solve(){
    int minn=1000005;
    int r,c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]+=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]);
            if(abs(2*dp[i][j]-sum)<minn){
                minn=abs(2*dp[i][j]-sum);
                r=i,c=j;
            }
            else if(abs(2*dp[i][j]-sum)==minn){
                if(i*j<r*c){
                    r=i,c=j;
                }
            }
        }
    }
    cout<<r<<" "<<c<<endl;
}
int main(){
    while(cin>>n>>m){
        sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>dp[i][j];
                sum+=dp[i][j];
            }
        }
        solve();
    }
    return 0;
}