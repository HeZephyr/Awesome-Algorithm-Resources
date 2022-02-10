#include<bits/stdc++.h>

using namespace std;
using ll = long long;
ll t;
ll n, m, a[300005], k;
int main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld%lld", &n, &k);
        if(n==1) printf("freesin\n");
        else if(1ll+k>=n){
            printf("pllj\n");
        } else {
            printf("freesin\n");
        }
    }
    return 0;
}