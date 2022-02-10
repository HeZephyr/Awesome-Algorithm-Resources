#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
typedef long long ll;
ll a[N], tot, b[N];
ll x, r;
ll Abs(ll a){
    if(a < 0)return -a;
    return a;
}
int main(){
    char op;
    while(scanf("%lld", &x) != EOF){ 
        a[++tot] = x;
    }
    r = a[tot], x = a[tot-1];
    tot-=2;
    sort(a+1, a+1+tot, greater<ll>());
    for(int i = 1; i <= tot; ++ i){
        if(Abs(a[i] - x) <= r){
            printf("%lld ", a[i]);
        }
    }
    return 0;
}