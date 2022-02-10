#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int t;
ll n;
int main(){
    scanf("%d", &t);
    for(int k = 1; k <= t; ++ k){
        scanf("%lld", &n);
        printf("Case %d: ", k);
        ll ans = 0;
        for(int l = 1, r; l <= n; l = r + 1){
            r = n / (n / l);
            ans += (n / l) * (r - l + 1);
        }
        if(ans & 1)puts("odd");
        else puts("even");
    }
    return 0;
}