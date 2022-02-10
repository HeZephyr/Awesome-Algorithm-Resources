#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl
#define int long long
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, a[N];
int ksm(int n, int q){
    int ans = 1;
    while(q){
        if(q & 1)ans = 1LL * ans * n % P;
        n = 1LL * n * n % P;
        q >>= 1;
    }
    return ans;
}
int fac[N];
void init(){
    fac[0] = fac[1] = 1;
    for(int i = 2; i <= n; ++ i){
        fac[i] = fac[i - 1] * i % P;
    }
}
void solve(){
    int cnt = 0;//奇数的数量。
    ll res = 0;
    for(int i = 1; i <= n; ++ i){
        if(a[i] % 2)++ cnt;
    }
    cout << cnt << endl;
    for(int i = 1; i <= cnt;  i += 2){
        //只有i个奇数的时候。
        res += fac[cnt] * ksm(fac[i], P - 2) % P * ksm(fac[cnt - i], P - 2) % P * (n - cnt + 1) % P * (n - cnt + 2) % P * ksm(2, P - 2) % P;
    }
    cout << res << endl;
}
signed main(){	
    scanf("%lld", &n);
    init();
    for(int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
    }
    solve();
    return 0;
}