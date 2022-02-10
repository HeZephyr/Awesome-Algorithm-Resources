/**
  *@author: pursuit
  *@Created: 2021-03-28 13:39
**/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=100+5;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

//动态规划，我们可以表示dp[i][j]表示为只取前i个笼子，j是否能够被凑出。
//则我们可以根据在取第i个笼子的时候来判断第i个物品取了多少件。若有一件是可以被凑出的，那么则成立。
//也就是说。dp[i][j]=dp[i-1][j]||dp[i][j-w[i]]||dp[i][j-2*w[i]]........我们检索即可。
//注意判断gcd是否为1。  

int n;
int dp[maxn][10005];
int a[maxn];
int Gcd(int n,int m){
    return m?Gcd(m,n%m):n;
}
void solve(){
    //背包问题。
    memset(dp,0,sizeof(dp));
    dp[0][0]=true;//初始状态设置好。
    for(int i=1;i<=n;i++){
        for(int j=0;j<=10000;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=a[i]){
                dp[i][j]=dp[i][j]||dp[i][j-a[i]];
            }
        }
    }
    int ans=0;
    for(int j=0;j<=10000;j++){
        if(!dp[n][j]){
            ans++;
        }
    }
    cout<<ans<<endl;
}
int main(){
    while(cin>>n){
        int gcd=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            gcd=Gcd(gcd,a[i]);
        }
        if(gcd!=1){
            cout<<"INF"<<endl;
            continue;
        }
        solve();
    }
    return 0;
}