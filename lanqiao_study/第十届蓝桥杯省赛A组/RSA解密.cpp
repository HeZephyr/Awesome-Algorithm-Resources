/**
  *@filename:RSA解密
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-12 13:01
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

ll n=1001733993063167141,d=212352;
ll p,q,e;
ll exGcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll gcd=exGcd(b,a%b,x,y);
    ll temp=x;
    x=y;
    y=temp-a/b*y;
    return gcd;
}
void solve(){
}
int main(){
    ll temp=sqrt(n);
    for(ll i=2;i<=temp;i++){
    }
    return 0;
}