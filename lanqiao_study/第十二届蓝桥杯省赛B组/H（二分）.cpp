/**
  *@filename:H
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-18 15:00
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

ll C(ll n,ll m){
    ll ans=1;
    for(ll i=n,j=1;i>=(n-m+1);i--,j++){
        ans=ans*i/j;
    }
    return ans;
}
ll n;
void solve(){
    if(n==1){
        cout<<1<<endl;
        return;
    }
    bool flag=false;
    ll l=3,r=n;
    while(l<r){
        ll mid=(l+r)>>1;
        if(judge(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
}
int main(){
    while(cin>>n){
        solve();
    }
    return 0;
}