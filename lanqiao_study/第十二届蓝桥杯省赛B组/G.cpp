/**
  *@filename:G
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-18 15:15
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//
int n;
int w[maxn];
int cnt[maxn];
int sum;
void dfs(int step,int ans){
    //step表示当前正在选择的砝码，ans为左边减右边的重量。
    if(step==n+1){
        //说明前n个已经选完了。
        if(ans<=0)return;
        cnt[ans]++;
        return;
    }
    dfs(step+1,ans+w[step]);//放左边。
    dfs(step+1,ans);//不放。
    dfs(step+1,ans-w[step]);//放右边。
}
void solve(){
    dfs(1,0);
    int ans=0;
    for(int i=1;i<=sum;i++){
        if(cnt[i]>0)ans++;
    }
    cout<<ans<<endl;
}
int main(){
    cin>>n;
    sum=0;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        sum+=w[i];
    }
    solve();
    return 0;
}