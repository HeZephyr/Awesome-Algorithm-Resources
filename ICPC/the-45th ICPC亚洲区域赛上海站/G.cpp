#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int n;
int cnt1, cnt2, Max;
void solve(){
    cnt1 = n / 3, cnt2 = n / 3;
    ll res = 1LL * (n - 3 + n % 3) * cnt1 / 2;
    res += 1LL * (1 + n / 3) * cnt2 / 2 * 2;
    cout<<res<<endl;
}
int main(){
    cin >> n;
    solve();
    return 0;
}