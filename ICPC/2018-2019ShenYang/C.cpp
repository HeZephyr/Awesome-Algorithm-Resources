#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9;
vector<ll>f(60);

ll fac(int n) {
    ll ans = 1;
    while (n) {ans = (ans * n) % mod; n--;}
    return ans;
}

void init() {
    f[1] = 1;
    for (int i = 2; i < 60; ++i)
        f[i] = (f[i - 1] + 2 * i - 3) % mod;
}
int main() {
    int t; cin >> t;
    init();
    for (int Case = 1; Case <= t; ++Case) {
        int n, k;
        cin >> n >> k >> mod; k = min(n - 1, k);
        cout << "Case #" << Case << ": ";
        cout << fac(k) * ((f[n - k] + (k + 1) * (n - k) % mod - 1) % mod) % mod << "\n";
    }
    return 0;
}