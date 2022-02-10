/**
  *@filename:B_AND_0_Sum_Big
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-19 21:39
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

ll t,n,k;
ll quick_pow(ll n,ll q){
    ll ans=1;
    while(q){
        if(q&1)ans=ans%mod*n%mod;
        n=n%mod*n%mod;
        q>>=1;
    }
    return ans;
}
void solve(){
    cout<<quick_pow(n,k)<<endl;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        solve();
    }
    return 0;
}