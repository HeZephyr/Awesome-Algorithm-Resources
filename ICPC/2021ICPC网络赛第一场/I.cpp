#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
typedef long long ll;
ll a[N], tot, b[N];
ll x, r;
ll Abs(ll a){
    if(a < 0)return a * (- 1);
    return a;
}
int main(){
    char op;
    while(scanf("%lld", &x) != EOF)a[++ tot] = x;
    x = a[tot - 1], r = a[tot];
    tot -= 2;
    int cnt = 0;
    for(int i = 1; i <= tot; ++ i){
        if(Abs(a[i] - x) <= r){
            b[++ cnt] = a[i];
        }
    }
    sort(b + 1, b + cnt + 1, greater<ll>() );
    for(int i = 1; i <= cnt; ++ i){
        cout << b[i] << " ";
    }
    if(cnt == 0)cout << endl;
    return 0;
}