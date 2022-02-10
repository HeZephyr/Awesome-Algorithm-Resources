/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-23 20:10
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
ll L,v,l,r;
void solve(){
    ll cnt = L / v - (r / v - (l - 1) / v);
    printf("%lld\n", cnt);
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> L >> v >> l >> r;
        solve();
    }
    return 0;
}