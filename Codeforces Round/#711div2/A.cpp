/**
  *@filename:A
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-30 14:42
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t;
ll n;
ll gcd(ll n,ll m){
    return n%m?gcd(m,n%m):m;
}
ll digit_sum(ll n){
    ll ans=0;
    while(n>0){
        ans+=n%10;
        n/=10;
    }
    return ans;
}
void solve(){
    while(true){
        if(gcd(n,digit_sum(n))>1){
            cout<<n<<endl;
            break;
        }
        n++;
    }
}
int main() {
    while(cin>>t){
        while(t--){
            cin>>n;
            solve();
        }
    }
    return 0;
}