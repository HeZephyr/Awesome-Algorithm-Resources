/**
  *@filename:分数
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-03 09:46
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

ll gcd(ll n,ll m){
    return n%m?gcd(m,n%m):m;
}
//我们发现，这实际上就是一个等比数列，公比为1/2.
void solve(){
    //利用等比数列求和公式a1(1-q^n)/(1-q)。当然我们也可以利用gcd来通分求和再约分。
    ll a=ll(powl(2,20)-1),b=ll(powl(2,19));
    cout<<a/gcd(a,b)<<"/"<<b/gcd(a,b)<<endl;//1048575/524288
}
int main(){
    solve();
    return 0;
}