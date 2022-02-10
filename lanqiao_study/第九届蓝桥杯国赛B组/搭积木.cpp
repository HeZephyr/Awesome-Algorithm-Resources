/**
  *@filename:搭积木
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-09 15:16
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=110;
const int mod = 1e9+7;

int n,m;//图纸的大小。
char g[N][N];
ll dp[N][N],c[N][N];//c[i][j]表示第i层前j个字符串有多少个'X'。
void solve(){
    //初始化dp数组。
    ll ans=1;//没有放也是一种情况。
    for(int i=1;i<=m;i++){
        for(int j=m;j>=i;j--){
            if(c[1][j]-c[1][i-1]==0){
                ans++;//这种是一种情况。
                dp[i][j]=dp[i][j+1]+dp[i-1][j]-dp[i-1][j+1]+1;
            }
        }
    }
    for(int t=2;t<=n;t++){
        for(int i=1;i<=m;i++){
            for(int j=m;j>=i;j--){
                if(c[t][j]-c[t][i-1]==0){
                    ans=(ans+dp[i][j])%mod;
                    dp[i][j]=(dp[i][j]+dp[i-1][j]+dp[i][j+1]-dp[i-1][j+1])%mod;
                }
                else{
                    //填不了，这里为0.
                    dp[i][j]=0;
                }
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    cin>>n>>m;
    for(int i=n;i;i--){
        cin>>g[i]+1;
        for(int j=1;j<=m;j++){
            c[i][j]=c[i][j-1]+(g[i][j]=='X');//前缀和数组。为了避免反程序员的思维，这里我们另类读入。
        }
    }
    solve();
    return 0;
}