/**
  *@filename:对局匹配
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-29 20:19
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,k,temp,maxx;//题目所问，即为任意两名用户的积分之差不等于K。
int cnt[maxn];//cnt[i]表示积分为i的出现次数。
int dp[maxn];//dp数组。有点像背包问题，我们让相差为k分的人为为一组。
void solve(){
    int ans=0;
    if(!k){
        //说明k为0，此时我们只需要统计积分不相同的即可。
        for(int i=0;i<=maxx;i++){
            if(cnt[i])ans++;
        }
    }
    else{
        //dp，我们通过k将其分成0~k-1组。
        for(int i=0;i<k;i++){
            int j;
            for(j=i;j<=maxx;j+=k){
                //对j进行情况分析。
                if(j-2*k>=0){
                    //说明可以选择j也可以不选择。如果不选择，那么就是继承上一次的dp[j-k];
                    dp[j]=max(dp[j-k],dp[j-2*k]+cnt[j]);//如果选择，就是加上上一次的dp[j-2*k]。
                }
                else if(j-k>=0){
                    //说明此时仍是选还是不选。
                    dp[j]=max(dp[j-k],cnt[j]);
                }
                else{
                    dp[j]=max(dp[j],cnt[j]);
                }
            }
            //由于退出的时候j已经大于maxx了，所以我们需要减去k。
            ans+=dp[j-k];
        }
    }
    printf("%d\n",ans);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        cnt[temp]++;
        maxx=max(maxx,temp);//保存当前最大值。
    }
    solve();
    return 0;
}