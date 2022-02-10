/**
  *@filename:A_Luntik_and_Concerts
  *@author: pursuit
  *@created: 2021-10-24 18:05
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
ll a, b, c;
void solve(){
    ll x = (a + 2 * b + 3 * c);
    if(x % 2 == 0)puts("0");
    else puts("1");
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> a >> b >> c;
        solve();
    }
    return 0;
}