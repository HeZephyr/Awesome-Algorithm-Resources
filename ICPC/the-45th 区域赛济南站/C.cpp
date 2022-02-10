#include<bits/stdc++.h>

using namespace std;
using ll = long long;
int a[3];
int main(){
    for(int i = 0; i < 3; ++ i)cin >> a[i];
    ll ans = 0;
    int x = min(a[0], a[1]);
    a[0] -= x, a[1] -= x;
    a[2] += x;
    ans += 2 * x;
    x = a[0] / 3;
    a[0] %= 3;
    ans += 3 * x;
    x = a[1] / 3;
    a[1] %= 3;
    ans += 6 * x;
    if(a[0] == 2)ans += 1;
    if(a[1] == 2)ans += 4;
    cout << ans << endl;
    return 0;
}