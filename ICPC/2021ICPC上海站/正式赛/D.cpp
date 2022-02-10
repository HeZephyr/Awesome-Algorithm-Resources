#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll N = 1e9;
ll p, q;
bool check(ll a, ll b){
    if(a * b == q && (a * a + b * b) == p){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int t;
    scanf("%d", &t);
    while(t -- ){
        cin >> p >> q;
        ll gcd = __gcd(p, q);
        p /= gcd, q /= gcd;
        ll temp = sqrt(p + 2 * q);
        if(temp * temp != (p + 2 * q)){
            puts("0 0");
        }
        else{
            ll x = temp * temp - 4 * q;
            if(x >= 0){
                ll x1 = (temp - sqrt(x)) / 2, x2 = (temp + sqrt(x)) / 2;
                if(x1 >= 1 && x1 <= N){
                    ll a = temp - x1;
                    if(a >= 1 && a <= N && check(a, x1)){
                        printf("%lld %lld\n", a, x1);
                    }
                    else{
                        puts("0 0");
                    }
                }
                else if(x2 >= 1 && x2 <= N){
                    ll a = temp - x2;
                    if(a >= 1 && a <= N && check(a, x2)){
                        printf("%lld %lld\n", a, x2);
                    }
                    else{
                        puts("0 0");
                    }
                }
                else{
                    puts("0 0");
                }
            }
            else{
                puts("0 0");
            }
        }
    }
    return 0;
}