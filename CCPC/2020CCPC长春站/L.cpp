#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 1e5+7;
ll ans[N];
ll exGcd(ll a, ll b, ll &x, ll &y){
    if(a == 0 && b == 0)return -1;
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    ll d = exGcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int main(){
    ll n, k, s, sum = 0;
    scanf("%lld%lld%lld", &n, &k, &s);
    sum = (n/(k+1ll)) * (1ll+k)*k/2ll;
    ll m = n%(k+1ll);
    for(ll i = 0ll;i < m;i++){
        sum += i;
    }
    if(s<sum){
        printf("-1\n");
        return 0;
    }
    s -= sum;
    //nx + (k+1)y = s;
    ll x, y;
    ll gcd = __gcd(n, k + 1);
    if(s % gcd){
        puts("-1");
        return 0;
    }
    exGcd(n, k + 1, x, y);
    ll temp = (k + 1) / gcd;
    x = (x + temp) * (s / gcd);
    x = (x % temp + temp) % temp;
    y = (s - n * x) / (k + 1);
    //cout << gcd << " " << x << " " << y << endl;
    if(x<0 || y<0){
        printf("-1\n");
        return 0;
    }
    m = y/n;
    ll mod = y%n;
    for(ll i = 0;i < n;i++){
        ans[i] = i%(k+1ll) + x + m*(k+1ll);
        if(i<mod) ans[i] += k+1ll;
    }
    for(ll i = 0;i < n;i++){
        printf("%lld ", ans[i]);
    }
    return 0;
}
