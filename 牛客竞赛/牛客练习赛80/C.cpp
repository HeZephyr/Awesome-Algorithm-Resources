/**
  *@filename:C
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-09 19:37
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 100019;

ll n;
ll quick_pow(ll n,ll q){
    int ans=1;
    while(q){
        if(q&1)ans=ans*n%mod;
        n=n*n%mod;
        q>>=1;
    }
    return ans;
}
void solve(){
    cout<<9*quick_pow(5,n-1)%mod<<endl;
}
int main(){
    while(cin>>n){
        solve();
    }
    return 0;
}