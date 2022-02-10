#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
int n;
ll a[N];
void solve(){
    //找到一个h，使得h最大且有h个大于等于h的。
    ll maxx = min(a[n],1LL * n);
    for(int i = n - 1; i >= 0; -- i){
        a[i] += a[i + 1];
        maxx = max(maxx,min(a[i],1LL * i));
    }
    printf("%lld\n", maxx);
}
int main(){
    while(~scanf("%d", &n)){
        for(int i = 0; i <= n; ++ i){
            scanf("%lld", &a[i]);
        }
        solve();
    }
    return 0;
}