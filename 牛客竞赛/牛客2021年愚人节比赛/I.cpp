/**
  *@filename:I
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-01 19:05
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

string s;
void solve(){
    int ans=0;
    for(int i=0;i<5;i++){
        ans+=powl(4,4-i)*(s[i]-'a');
    }
    cout<<ans<<endl;
}
int main(){
    while(cin>>s){
        solve();
    }
    return 0;
}