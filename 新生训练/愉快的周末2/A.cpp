/**
  *@filename:A
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-21 19:48
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

ll n,m;
int result;
void dfs(ll n,int step){
    if(n>m){
        return;
    }
    if(n==m){
        result=step;
        return;
    }
    dfs(n*2,step+1);
    dfs(n*3,step+1);
}
void solve(){
    result=-1;
    dfs(n,0);
    cout<<result<<endl;
}
int main() {
    while(cin>>n>>m){
        solve();
    }
    return 0;
}