#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    for (int Case = 1; Case <= t; ++Case) {
        ll n, m, k;
        cin >> n >> m >> k;
        cout << "Case #" << Case << ": ";
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        if (k == 1) {
            cout << m << "\n";
            continue;
        }
        ll p = n - m + 1;
        ll ans = (p + k - 1) % p;
        while (p < n) {
            if (m > k) {
                ll t = p - ans;
                t = min(n - p, t / k);
                p += t;
                ans = (ans + t * k) % p;
                if (p == n)break;
            }
            p++;
            ans = (ans + k) % p;
            if (p == n)break;
        }

        cout << ans + 1 << '\n';
    }
}