#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5 + 10;
int n, m, t;
ll C(ll n, ll m){
    ll ans = 1;
    for(int i = n; i >= n - m + 1; -- i){
        ans = ans * i / (n - i + 1);
    }
    return ans;
}
int main(){
    scanf("%d%d%d", &n, &m, &t);
    ll res = 0;
    for(int i = 4; i <= t - 1; ++ i){
        res += C(n, i) * C(m, t - i);
    }
    printf("%lld\n", res);
    return 0;
}