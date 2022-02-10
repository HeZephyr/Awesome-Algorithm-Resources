/**
  *@filename:D
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-08 08:43
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 300000 + 5;
const ll P = 998244353;

int n,a[N];
//需要非降序排列p，非升序排列q。
//需要利用逆元求解组合数。
ll fac[N],inv[N];
ll quick_pow(ll n,ll q){
    ll res = 1;
    while(q){
        if(q & 1)res = (res * n) % P;
        n = (n * n) % P;
        q >>= 1;
    }
    return res;
}
void init(){
    fac[0] = 1;
    //求阶乘。
    for(int i = 1; i < N; ++ i){
        fac[i] = fac[i - 1] * i % P;
    }
    inv[N - 1] = quick_pow(fac[N - 1],P - 2);
    for(int i = N - 2; i >= 0; -- i){
        inv[i] = inv[i + 1] * (i + 1) % P;
    }
}
ll C(ll n,ll m){
    if(m < 0 || m > n)return 0;
    return fac[n] * inv[m] % P * inv[n - m] % P;
}
void solve(){
    //无论怎么分，都是大的一半减去小的一半。
    ll sum = 0;
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n / 2; ++ i){
        sum = (sum + abs(a[n - i + 1] - a[i])) % P;
    }
    printf("%lld\n",1LL * C(n,n / 2) * sum % P);
}
int main(){
    init();
    scanf("%d", &n);
    n *= 2;
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}