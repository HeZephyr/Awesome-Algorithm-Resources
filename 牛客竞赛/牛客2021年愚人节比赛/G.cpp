/**
  *@filename:G
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-01 19:41
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const ll mod = 1e9+7;

ll n;
ll quick_pow(ll n,ll q){
    ll ans=1;
    while(q){
        if(q&1)ans=ans*n%mod;
        n=n*n%mod;
        q>>=1;
    }
    return ans;
}
void solve(){
}
int main(){
    while(cin>>n){
        cout<<n%mod<<endl;
        cout<<(2*(n-1)+1)%mod<<endl;
        cout<<(n%mod*n%mod)%mod<<endl;
        cout<<quick_pow(2,n-1)<<endl;
        cout<<quick_pow(2,quick_pow(2,n-1))<<endl;
        cout<<(n&1?1:2)<<endl;
        solve();
    }
    return 0;
}