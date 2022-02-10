#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int t;
ll k, x;
ll cal(ll n){
    //n为选取了多少项。
    ll minn = min(n, k);
    ll ans = minn * (minn + 1) / 2;
    n -= minn;
    ans += (n * (k - 1) - n * (n - 1) / 2);
    //cout << "ans:" << ans << endl;
    return ans;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> k >> x;
        ll res = 0;
        if(x >= k * k){
            res = 2 * k - 1;
            x = 0;
        }
        ll l = 1, r = 2 * k;
        while(l < r){
            ll mid = (l + r) >> 1;
            if(cal(mid) > x){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        if(cal(l) > x)-- l;
        //printf("l:%lld\n", l);
        res += l;
        x -= cal(l);
        if(x > 0){
            ++ res;
        }
    cout << res << endl;
    }
    return 0;
}