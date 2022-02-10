/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-08-13 14:03
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 998244353;
const int INF = 0x3f3f3f3f;

ll d,u,v;
int q,fac[N];
map<ll,ll> p;
void init(){
    //预处理n!
    fac[0] = fac[1] = 1;
    for(int i = 2; i < N; ++ i){
        fac[i] = 1LL * fac[i - 1] * i % P;
    }
}
ll ksm(ll n,ll q){
    ll ans = 1;
    while(q){
        if(q & 1)ans = ans * n % P;
        n = n * n % P;
        q >>= 1;
    }
    return ans;
}
ll cal(ll x){
    //需要计算x到y的所有最短路径，而其都经过gcd(x,y)。
    //x移动到gcd(x,y)的最短路径，就是x除以x/(gcd(x,y))的质因子，除的顺序是任意的。
    ll sum1 = 0,sum2 = 1;
    for(ll i = 2; i * i <= x; ++ i){
        if(x % i == 0){
            ll num = 0;
            while(x % i == 0){
                x /= i;
                num ++;
            }
            sum2 = sum2 * ksm(fac[num], P - 2) % P;//除法取模边乘法。
            sum1 += num;
        }
    }
    if(x > 1){
        sum1 ++;
    }
    sum1 = sum2 * fac[sum1] % P;
    return sum1;
}
void solve(){
    for(ll i = 1; i * i <= d; ++ i){
        if(d % i == 0){
            p[i] = cal(i);
            p[d / i] = cal(d / i);
        }
    }
    while(q -- ){
        scanf("%lld%lld", &u, &v);
        ll k = __gcd(u,v);
        printf("%lld\n", p[u / k] * p[v / k] % P);
    }
}
int main(){	
    init();
    scanf("%lld%d", &d, &q);
    solve();
    return 0;
}