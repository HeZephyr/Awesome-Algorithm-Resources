#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0), cin.tie(0);
#define is empty()
#define bk back()
#define x first
#define y second
#define pb push_back
#define pob pop_back()
typedef long long LongBigData;
typedef pair<LongBigData, LongBigData> pii;

LongBigData n, c;
vector<LongBigData> cs;
vector<pii> s(1, {0, 0});
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        cs.pb(c);
    }
    LongBigData tot = 0, cur = 0;
    for (int i = 0; i+1 < n; i += 2) {
        LongBigData a = cs[i], b = cs[i+1];
        cur += a-b;
        tot += min(b, cur+b-s[0].x);
        while (!s.is && s.bk.x > cur) {
            tot += s.bk.y;
            s.pob;
        }

        if (!s.is && s.bk.x == cur) {
            tot += s.bk.y;
            ++s.bk.y;
        } else {
            if (s.is) {
                s.pb({cur, 0});
            } else {
                s.pb({cur, 1});
            }
        }
    }

    cout << tot;
}