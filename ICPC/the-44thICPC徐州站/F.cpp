#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e3 + 10;
int t;
ll x, f[N];
void init(){
    for(ll i = 0; i <= 5000; ++ i){
        f[i] = pow(i, 3);
    }
}
ll _abs(ll x){
    return x > 0 ? x : -x;
}
int check(ll a, ll b, ll c){
    ll q = f[a], y = f[_abs(b)], z = f[_abs(c)];
    if(b < 0)y *= -1;
    if(c < 0)z *= -1;
    if(q + y + z == x)return 1;
    else if(q + y + z > x)return 2;
    return 0;
}
int main(){
    scanf("%d", &t);
    init();
    while(t -- ){
        scanf("%lld", &x);
        bool flag = false;
        for(ll a = 0; a <= 5000; ++ a){
            for(ll b = -5000; b <= 5000; ++ b){
                ll l = -5000, r = 5001;
                while(l < r){
                    ll mid = (l + r) >> 1;
                    if(check(a, b, mid) >= 1){
                        r = mid;
                    }
                    else{
                        l = mid + 1;
                    }
                }
                if(check(a, b, l) == 1){
                    flag = true;
                    printf("%lld %lld %lld\n", a, b, l);
                    break;
                }
            }
            if(flag)break;
        }
        if(!flag)puts("impossible");
    }
    return 0;
}