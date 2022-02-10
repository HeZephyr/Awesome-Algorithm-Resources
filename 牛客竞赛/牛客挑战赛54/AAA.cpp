#include <bits/stdc++.h>
#define PII pair<int,int>
#define ll long long

using namespace std;

const double eps = 1e-8;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
const int INF = 1 << 30;
inline void swap(int& x, int& y) { x ^= y ^= x ^= y; }
inline int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int n;
int cnt0, cnt1;
int cnt[2];
int main() {
    scanf("%d", &n);
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1')cnt1++;
        else cnt0++;
    }
    s = s + s;
    int len = s.length();
    //cout << len << endl;
    int L = 0, R = -1;
    int ans = 0;
    while (L < n) {
        while ((R - L + 1) * 2 < n) {
            if(R == len - 1)break;
            cnt[s[++R] - '0']++;
        }
        if ((R - L + 1) * 2 == n && cnt[0] * 2 == cnt0 && cnt[1] * 2 == cnt1)ans++;
        cnt[s[L] - '0']--;
        L++;
    }
    printf("%d\n", ans);
    return 0;
}