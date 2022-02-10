/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-09-15 18:14
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
void solve(){
    if(n % 2050){
        cout << -1 << endl;
    }
    else{
        n /= 2050;
        ll res = 0;
        while(n){
            res += n % 10;
            n /= 10;
        }
        cout << res << endl;
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        solve();
    }
    return 0;
}