#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
long long n, k, t;
int main(){
    long long  t, a1, a2, b1, b2, c1, c2;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld%lld%lld%lld%lld%lld", &a1, &b1, &c1, &a2, &b2, &c2);
        long long ans = 0ll;
        long long tem = min(a2, c1);
        ans += tem, a2 -= tem, c1 -= tem;
        tem = min(b2, a1);
        ans += tem, b2 -= tem, a1 -= tem;
        tem = min(c2, b1);
        ans += tem, c2 -= tem, b1 -= tem;

        tem = min(a1, a2);
        a1 -= tem, a2 -= tem;
        tem = min(b1, b2);
        b1 -= tem, b2 -= tem;
        tem = min(c1, c2);
        c1 -= tem, b2 -= tem;

        ans -= a2+b2+c2;
        printf("%lld\n", ans);
    }
    return 0;
}