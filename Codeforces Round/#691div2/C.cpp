/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-24 21:44
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m;
ll a[N], b[N];
//gcd(a1 + bj, ... ,an + bj) = gcd(a1 + bj, a2 - a1, a3 - a2)。
void solve(){
    ll gcd = 0;
    for(int i = 2; i <= n; ++ i){
        gcd = __gcd(a[i] - a[i - 1], gcd);
    }
    for(int i = 1; i <= m; ++ i){
        printf("%lld ", ll(abs(__gcd(a[1] + b[i], gcd))));
    }
    puts("");
}
int main(){	
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
    }
    for(int i = 1; i <= m; ++ i){
        scanf("%lld", &b[i]);
    }
    solve();
    return 0;
}