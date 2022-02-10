#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

ll x, y, z;
inline void out(__int128 t){
    if(t > 9)out(t / 10);
    putchar(t % 10 + '0');
}
__int128 check(__int128 x, __int128 y){
    __int128 ans = 1;
    for(__int128 i = 1; i <= y; i += 1){
        ans *= x;
    }
    return ans;
}
void solve(){
    __int128 l = x, r = y, k = z;
    __int128 res = 0;
    if(k == 1){
        res = (l + r) * (r - l + 1) / 2;
    }
    else if(k == 2){
        __int128 t1 = sqrt(x), t2 = sqrt(y);
        __int128 ans1 = t1 * (t1 + t1 * (t1 - 1)), ans2 = t2 * (t2 + t2 * (t2 - 1));
        //有t1项。
        __int128 temp1 = (t1 + 1) * t1 * (2 * t1 + 1) / 6, temp2 = (t2 + 1) * t2 * (2 * t2 + 1) / 6;
        ans1 -= temp1, ans2 -= temp2;
        /* out(ans1);
        printf(" ");
        out(ans2);
        printf(" "); */
        ans1 += (l - check(t1, 2)) * t1;
        ans2 += (r + 1 - check(t2, 2)) * t2;
        /* out(ans1);
        printf(" ");
        out(ans2);
        printf(" "); */
        res = ans2 - ans1;
    }
    else{
        __int128 cnt0 = 0, cnt1 = 0;
        for(__int128 i = 1; check(i, k) < l; i += 1){
            if(check(i + 1, k) < l){
                cnt0 += (check(i + 1, k) - check(i, k)) * i;
            }
            else{
                cnt0 += (l - check(i, k)) * i;
            }
        }
        for(__int128 i = 1; check(i, k) <= r; i += 1){
            if(check(i + 1, k) <= r){
                cnt1 += (check(i + 1, k) - check(i, k)) * i;
            }
            else{
                cnt1 += (r - check(i, k) + 1) * i;
            }
        }
        res = cnt1 - cnt0;
    }
    out(res);
}
int main(){	
    cin >> x >> y >> z;
    solve();
    return 0;
}