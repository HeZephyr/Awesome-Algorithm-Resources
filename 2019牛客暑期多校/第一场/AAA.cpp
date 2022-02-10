#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll = long long;
using pdd = pair<ll, ll>;
const int N = 1e5+7;
const int p = 1e2;
pdd a, b, c;
ll area(pdd a, pdd b, pdd c){
    ll res = 1ll * abs(a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x)*11;
    return res;
}
int main(){
    while(cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y){
        ll ans = area(a, b, c);
        printf("%lld\n", ans);
    }
    return 0;
}