#include<bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
const int N = 2e5 + 10;

int n, l, r, seed;
int a[N];
ll xorshift64(){
    ll x = seed;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    return seed = x;
}
int get(){
    return xorshift64() % (r - l + 1) + l;
}
int main(){
    scanf("%d%d%d%d", &n, &l, &r, &seed);
    for(int i = 1; i <= n; ++ i){
        a[i] = get();
    }
    for(int i = 1; i <= n; ++ i){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}