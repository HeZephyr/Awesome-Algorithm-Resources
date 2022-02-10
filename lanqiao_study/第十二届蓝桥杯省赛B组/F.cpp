/**
  *@filename:F
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-18 14:57
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

ll n;
void solve(){
    n/=1000;
    printf("%02d:%02d:%02d\n",(n%(24*3600))/3600,n%3600/60,n%60);
}
int main(){
    while(cin>>n){
        solve();
    }
    return 0;
}