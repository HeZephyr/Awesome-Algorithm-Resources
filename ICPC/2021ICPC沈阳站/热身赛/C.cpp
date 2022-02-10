#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e6 + 10;
int n, k;
int a[N], b[N];
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    ll res = 0;
    sort(b + 1, b + n + 1, greater<int>() );
    for(int i = 1; i <= k; ++ i){
        res += b[i];
    }
    printf("%lld\n", res);
    return 0;
}