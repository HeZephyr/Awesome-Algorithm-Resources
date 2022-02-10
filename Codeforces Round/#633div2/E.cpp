/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-08-15 12:28
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
ll n;
int f[3][4] = {{0,3,1,2},{},{0,2,3,1}};
ll cal(ll a,ll b){
    ll res = 0, p = 1;
    if(b == 1)return a;
    while(a){
        res = res + f[b][a % 4] * p;
        a >>= 2;
        p <<= 2;
    }
    return res;
}
void solve(){
    ll j = 1,a;
    while(j <= n)j <<= 2;//求四进制下的最高位。
    j >>= 2;
    if(j + 2 >= n)a = j;//判断是否在该行。
    else a = j + (n - j) / 3;
    printf("%lld\n", cal(a,n % 3));
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%lld", &n);
        solve();
    }
    return 0;
}