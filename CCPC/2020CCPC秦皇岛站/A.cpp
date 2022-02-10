#include<bits/stdc++.h>

using namespace std;
using ll = long long;
int t, r, b;
int main(){
    cin >> t;
    for(int i = 1; i <= t; ++ i){
        cin >> r >> b;
        ll x = r * (r - 1) / 2, y = (b + r) * (b + r - 1) / 2;
        ll gcd = __gcd(x, y);
        x /= gcd, y /= gcd;
        cout << "Case #" << i << ": " << x << "/" << y << endl;
    }
    return 0;
}