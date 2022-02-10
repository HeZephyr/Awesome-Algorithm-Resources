/**
  *@filename:第一题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-14 08:27
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;


bool check(int x){
    if(x%4==0&&x%6==0)return true;
    else return false;
}
void solve(){
    int ans=0;
    for(int i=1;i<=2020;i++){
        if(check(i))ans++;
    }
    cout<<ans<<endl;//168
}
int main(){
    
    solve();
    return 0;
}