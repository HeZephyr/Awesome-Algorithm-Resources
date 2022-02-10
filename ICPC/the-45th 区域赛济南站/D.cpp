#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5+7;
struct node{
    ll l, r;
    bool operator < (const node x) const{
        if(r==x.r) return l>x.l;
        else return r<x.r;
    }
}a[N];
int main(){
    ll n;
    scanf("%lld\n", &n);
    for(ll i = 1;i <= n;i++){
        scanf("%lld%lld", &a[i].l, &a[i].r);
    }
    sort(a+1, a+1+n);
    ll tem = a[1].l;
    ll ans = tem;
    //printf("ans = %lld\n", ans);
    for(ll i = 2;i <= n;i++){
        if(a[i].l <= tem){
            ans += tem;
        } else {
            tem = a[i].l;
            ans += tem;
        }
        //printf("ans = %lld\n", ans);
    }
    printf("%lld\n", ans);
    return 0;
}