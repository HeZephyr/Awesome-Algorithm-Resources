/**
  *@filename:B_Special_Numbers
  *@author: pursuit
  *@created: 2021-10-08 23:12
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t;
ll n, k;
ll pow2[31];
void init(){
    pow2[0] = 1;
    for(int i = 1; i < 31; ++ i){
        pow2[i] = pow2[i - 1] * 2;
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
    ll res = 0;
    for(int i = 30; i >= 0; -- i){
        if(k >= pow2[i]){  
            res = (res + ksm(n, i)) % P;
            k -= pow2[i];
        }
    }
    printf("%lld\n", res);
}
int main(){	
    cin >> t;
    init();
    while(t -- ){
        cin >> n >> k;
        solve();
    }
    return 0;
}