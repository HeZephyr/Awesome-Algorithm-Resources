/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-18 19:03
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;


ll fac[1000000+5];		//阶乘
ll inv[1000000+5];		//逆元 
int n;
ll quickMod(ll a,ll b){
	ll ans = 1;
	while (b){
		if (b&1)
			ans = ans * a % P;
		a = a*a % P;
		b >>= 1;
	}
	return ans;
}
 
void getFac()
{
	fac[0] = inv[0] = 1;
	for (int i = 1 ; i <= 1000000 ; i++)
	{
		fac[i] = fac[i-1] * i % P;
		inv[i] = quickMod(fac[i],P - 2);		//表示i的阶乘的逆元 
	}
}
 
ll getC(ll n,ll m){		//C(n,m) = n!/((n-m)!*m!) % (1e9+7){
	return fac[n] * inv[n-m] % P * inv[m] % P;
}
void solve(){
    ll sum = 1;
    for(int i = 0; i <= n - 1; ++ i){
        sum = sum * getC(n - 1,i) % P;
    }
    cout << sum << endl;
}
int main(){
    getFac();
    cin >> n;
    solve();
    return 0;
}