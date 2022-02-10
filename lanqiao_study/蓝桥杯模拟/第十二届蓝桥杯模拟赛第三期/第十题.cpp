/**
  *@filename:第十题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-14 15:17
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000 + 5;
const int mod = 1000000+7;

//既然是找上升子序列。那么我们就应该想到是动态规划了
int n,k;
int a[maxn];
int dp[maxn][maxn];//dp[i][j]表示以i为结尾，长度为j的上升子序列数量。
void solve(){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)dp[i][1]=1;//初始化，长度为1的上升子序列就是它本身。
    for(int i=1;i<=n;i++){
        for(int j=2;j<=k;j++){
            int cnt=0;
            for(int z=1;z<i;z++){
                //以i结尾长度为j的可以由满足条件的1~i-1,j-1得到
                if(a[i]>a[z]){
                    dp[i][j]+=dp[z][j-1];
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=dp[i][k];
    }
    cout<<ans<<endl;
}
int main(){
    while(cin>>n>>k){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        solve();
    }
    return 0;
}