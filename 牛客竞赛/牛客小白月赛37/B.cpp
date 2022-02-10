/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-27 19:12
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e7 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int a[10],f[N],sum1,sum2 = 1;
void init(){
    f[1] = f[0] = 1;
    for(int i = 2; i < N; ++ i){
        f[i] = 1LL * i * f[i - 1] % P;
    }
}
int ksm(int n,int q){
    int ans = 1;
    while(q){
        if(q & 1) ans = 1LL * ans * n % P;
        q >>= 1, n = 1LL * n * n % P;
    }
    return ans;
}
void solve(){
    //debug(sum1),debug(sum2);
    cout << 1LL * f[sum1] * ksm(sum2, P - 2) % P << endl;
}
int main(){	
    init();
    for(int i = 0; i < 10; ++ i){
        cin >> a[i];
        sum1 += a[i];
        sum2 = 1LL * sum2 * f[a[i]] % P;
    }
    solve();
    return 0;
}