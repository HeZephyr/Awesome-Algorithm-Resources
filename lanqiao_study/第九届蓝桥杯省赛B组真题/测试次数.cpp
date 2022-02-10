/**
  *@filename:测试次数
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-08 20:05
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int dp[4][1005];//dp[i][j]表示现在还有i部手机，且待测楼层有j时，最坏运气下的最少的测试次数。
void solve(){
}
int main(){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=1000;j++){
            //无论有几部手机，运气最差的测试次数就是楼层的高度。
            dp[i][j]=j;
        }
    }
    //接下来开始模拟，对于只有一个手机的时候，我们无法再进行优化，因为只有一个手机我们只能从第一层测到后面。
    for(int i=2;i<=3;i++){
        //开始模拟有两个手机的时候。
        for(int j=1;j<=1000;j++){
            //对于这些状态。在j楼层的状态转移情况。
            for(int k=1;k<j;k++){
                //在j楼层的时候1~j-1层的测试情况，若摔坏了，则手机数量减一，下次去楼下测试即可，最多测试k-1次。
                //若没摔坏，则手机的数量不变，下一次要去楼上测试，最多再测试j-k次。
                dp[i][j]=min(dp[i][j],max(dp[i-1][k-1],dp[i][j-k])+1);
            }
        }
    }
    cout<<dp[3][1000]<<endl;
    return 0;
}