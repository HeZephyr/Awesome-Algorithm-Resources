/**
  *@filename:Matrix
  *@author: pursuit
  *@created: 2021-09-04 13:25
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 3e7 + 10;
const int P = 998244353;
const int INF = 0x3f3f3f3f;

int t, n;
int fac[N];
void init(){
    fac[0] = fac[1] = 1;
    for(int i = 2; i < N; ++ i){
        fac[i] = 1LL * fac[i - 1] * i % P;
    }
}
int ksm(int n, int q){
    int ans = 1;
    while(q){
        if(q & 1)ans = 1LL * ans * n % P;
        q >>= 1;
        n = 1LL * n * n % P;
    }
    return ans;
}
void solve(){
    int res = 0;
    for(int i = 1; i <= n; ++ i){
        res = (res + (1LL * fac[n * n - i] * ksm(fac[n - 1], P - 2) % P * ksm(fac[n * n - i - n + 1], P - 2) % P)) % P;
        //cout << res << endl;
    }
    res = 1LL * res * n % P * fac[n] % P * fac[n * n - n] % P;
    cout << res << endl;
}
int main(){	
    init();
    cin >> t;
    while(t -- ){
        cin >> n;
        solve();
    }
    return 0;
}