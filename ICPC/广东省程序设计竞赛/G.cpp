#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll q, n, x;
    scanf("%lld", &q);
    while(q--){
        scanf("%lld", &n);
        ll cnt1 = 0ll, cnt2 = 0ll;
        for(ll i = 1;i <= n;i++){
            scanf("%lld", &x);
            if(x&1){
                cnt1 += (x+1)/2;
            } else {
                cnt2 += x/2-1;
            }
        }
        if(cnt1<=cnt2) printf("Bob\n");
        else printf("Alice\n");
    }
    return 0;
}