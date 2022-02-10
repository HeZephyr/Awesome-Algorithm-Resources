/**
  *@filename:倍数问题-动态规划
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-08 12:20
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,K;
int dp[4][1005];
void solve(){
}
int main(){
    while(cin>>n>>K){
        vector<vector<int> > nums(K);
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            nums[temp%K].push_back(temp);
        }
        for(int i=0;i<K;i++){
            if(nums[i].size())sort(nums[i].begin(),nums[i].end(),greater<int>());//降序排列。
        }
        memset(dp,-0x3f3f,sizeof(dp));
        dp[0][0]=0;//没有选取任何数，自然为0.
        for(int index=0;index<K;index++){
            for(int i=0;i<3&&i<nums[index].size();i++){
                int x=nums[index][i];
                for(int j=3;j>=1;j--){
                    for(int k=0;k<K;k++){
                        dp[j][k]=max(dp[j][k],dp[j-1][((k-x)%K+K)%K]+x);
                    }
                }
            }
        }
        cout<<dp[3][0]<<endl;
    }
    solve();
    return 0;
}