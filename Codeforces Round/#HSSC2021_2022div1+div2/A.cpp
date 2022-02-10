#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int t, n;
void solve(){
    ll res = 0;
    int d = 0;
    while(n){
        if(d == 0 && n % 10 == 9){
            ++ res;
        }
        else if(d > 0){
            res += 1LL * (n % 10) * pow(10, d - 1);
        }
        n /= 10;
        ++ d;
    }
    printf("%lld\n", res);
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        solve();
    }
    return 0;
}