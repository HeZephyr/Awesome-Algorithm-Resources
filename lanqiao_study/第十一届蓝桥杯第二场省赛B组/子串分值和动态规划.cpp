/**
  *@filename:子串分值和动态规划
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 22:05
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;
char s[maxn];
int pos[27];//记录第i个字母最后出现的位置。
int dp[maxn];
void solve(){
    n=strlen(s+1);
    memset(pos,0,sizeof(pos));
    memset(dp,0,sizeof(dp));
    ll ans=0;
    for(int i=1;i<=n;i++){
        int temp=s[i]-'a';
        dp[i]=dp[i-1]+i-pos[temp];
        pos[temp]=i;
        ans+=dp[i];
    }
    cout<<ans<<endl;
}
int main(){
    while(scanf("%s",s+1)!=EOF){
        solve();
    }
    return 0;
}