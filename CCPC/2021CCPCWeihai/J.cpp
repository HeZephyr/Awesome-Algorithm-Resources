#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll t, a, b;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld", &a, &b);
        ll p = 180ll * b;
        ll gc = 1ll * gcd(a, p);
        printf("%lld\n", p/gc-1ll);
    }
    return 0;
}