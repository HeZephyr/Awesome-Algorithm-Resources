#include<bits/stdc++.h>

using namespace std;
using ll = long long;
ll t;
ll n, m, a[300005], k;
int main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld%lld", &n, &k);
        ll r = 1e9+10, l = 1ll, tem;
        m = n + k*(k-1ll)/2ll;
        while(l<=r){
            ll mid = l+r>>1;
            if((1ll+mid)*mid/2ll+k+k >= m){
                printf("tem = %lld, m = %lld\n", tem, m);
                tem = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        printf("pos = %lld\n", tem);
        if(tem==1) printf("pllj\n");
        else if((tem-1ll)*tem/2 + k + tem + k >= m){
            printf("freesin\n");
        } else {
            printf("pllj\n");
        }
    }
    return 0;
}