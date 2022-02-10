/**
  *@filename:小朋友崇拜圈
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-09 17:26
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;//n个小朋友。
int friends[maxn];
int ans,maxx;
bool vis[maxn];
void dfs(int i,int obj){
    if(vis[i]&&i!=obj){
        return;
    }
    if(vis[i]&&i==obj){
        //说明到达了。形成了一个回环。
        maxx=max(ans,maxx);
        return;
    }
    ans++;
    vis[i]=true;
    dfs(friends[i],obj);
    vis[i]=false;
}
void solve(){
    ans,maxx=0;
    for(int i=1;i<=n;i++){
        ans=0;
        dfs(i,i);
    }
    cout<<maxx<<endl;
}
int main(){
    while(cin>>n){
        int temp;
        for(int i=1;i<=n;i++){
            cin>>temp;
            friends[i]=temp;
        }
        solve();
    }
    return 0;
}