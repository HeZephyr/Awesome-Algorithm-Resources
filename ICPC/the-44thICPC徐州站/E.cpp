#include<bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
const int N = 1e5+7;

ll a[N];
int main(){
    ll t, n, x, y, m, sum, tem, cnt;
    scanf("%llu", &t);
    while(t--){
        scanf("%llu%llu%llu", &n, &x, &y);
        m = sum = cnt = 0ll;
        for(ll i = x;i <= y;i*=x){
            a[++cnt] = i;
            sum += y/i;
        }
        for(ll i = 1;i <= n;i++){
            scanf("%lld", &tem);
            if(tem<x) continue;
            for(ll j = 1;tem <= a[j];j++){
                m += tem/a[j];
            }
        }
        printf("%llu\n", sum-m);
    }
}