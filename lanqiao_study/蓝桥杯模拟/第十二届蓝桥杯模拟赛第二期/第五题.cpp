/**
  *@filename:第五题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-14 08:48
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

string s="LANQIAO";
void solve(){
    int ans=0;
    for(int i=0;i<7;i++){
        for(int j=i+1;j<7;j++){
             ans+=abs(s[j]-s[i]);
        }
    }
    cout<<ans<<endl;//162
}
int main(){
    
    solve();
    return 0;
}