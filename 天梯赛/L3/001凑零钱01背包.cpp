/**
  *@filename:001凑零钱01背包
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-23 11:10
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 10000 + 5;
const int mod = 1e9+7;

int n,m;
int dp[maxn],a[maxn];
bool vis[maxn][maxn];//vis[i][j]判断该状态是否被选择。
void solve(){
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n,greater<int>() );
    for(int i=1;i<=n;i++){
        for(int j=m;j>=a[i];j--){
            if(dp[j]<=dp[j-a[i]]+a[i]){
                dp[j]=dp[j-a[i]]+a[i];
                vis[i][j]=true;
            }
        }
    }
    if(dp[m]!=m)puts("No Solution");
    else{
        vector<int> result;
        int v=m,index=n;
        while(v>0){
            if(vis[index][v]){
                result.push_back(a[index]);
                v-=a[index];
            }
            index--;
        }
        for(int i=0;i<result.size();i++){
            cout<<result[i];
            i==result.size()-1?cout<<endl:cout<<' ';
        }
    }
    solve();
    return 0;
}