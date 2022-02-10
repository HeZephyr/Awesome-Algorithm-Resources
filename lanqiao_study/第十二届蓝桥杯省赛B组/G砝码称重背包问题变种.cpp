
/**
  *@filename:G砝码称重背包问题变种
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-19 18:55
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//背包dp。累加三种方案数即可。
int n;
int w[105];
int dp[105][maxn<<2];//dp[i][j]表示的即是前i个砝码中能凑成重量j的方案数。
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>w[i];
	//由于我们在进行决策的时候会出现负数，所以我们需要将数组进行偏移一个maxn确保枚举的时候不会出现错误。
	dp[0][maxn]=1;//注意设立起始值作为更新点。
	for(int i=1;i<=n;i++){
		for(int j=-maxn+w[i];j<=maxn;j++){
			//从小到大开始枚举。
			//不选，加上，减去三种决策。
			dp[i][j+maxn]=dp[i-1][j+maxn]+dp[i-1][j+maxn+w[i]]+dp[i-1][j+maxn-w[i]];
		}
	}
	int ans=0;//累加所有出现的状态。
	for(int j=maxn+1;j<=maxn*2;j++){
		if(dp[n][j])ans++;
	}
	cout<<ans<<endl;
	return 0;
}