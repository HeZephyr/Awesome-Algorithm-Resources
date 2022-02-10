/**
  *@filename:A
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-01 20:36
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

char x;
string s;
void solve(){
}
int main(){
    while(cin>>x){
        cin>>s;
        int ans=0;
        for(auto &temp:s){
            if(x==temp){
                ans++;
            }
        }
        cout<<ans<<endl;
        solve();
    }
    return 0;
}