#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        ll x;
        scanf("%lld", &x);
        ll n = sqrt(x);
        printf("%lld %lld %lld %lld\n", (n - 1) * (n - 2), (n -1) * (n - 1), (n - 2) * (n + 1), (n + 1) * (n - 1));
    }
    return 0;
}