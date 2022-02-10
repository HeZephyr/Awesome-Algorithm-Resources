#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 10;
int main(){
    ll t, n, m, x, y;
    scanf("%lld", &t);
    while(t -- ){
        scanf("%lld%lld%lld%lld", &n, &m, &x, &y);
        if(n>m) swap(n, m);
        if(n==1ll){
            printf("%lld\n", (m-1ll)*x);
            continue;
        }
        ll ans = 0;
        if(2ll*x <= y){
            ans = (n-1ll+m-1ll)*x;
        }
        else if(x<=y){
            ans = (n-1ll)*y + max(m-n, 0ll)*x;
        } else {
            if((m-n)%2==0){
                ans = (n-1ll)*y + max(m-n, 0ll)*y;
            }else{
                m--;
                ans = x;
                ans += (n-1ll)*y + max(m-n, 0ll)*y;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}