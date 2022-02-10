/**
  *@filename:第六题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-14 08:51
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int h,m,t;
void solve(){
    m+=t;
    h+=m/60;
    m%=60;
    cout<<h<<endl;
    cout<<m<<endl;
}
int main(){
    while(cin>>h>>m){
        cin>>t;
        solve();
    }
    return 0;
}