/**
  *@filename:D_Moderate_Modular_Mode
  *@author: pursuit
  *@created: 2021-10-30 23:32
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
ll x, y;
void solve(){
    // n mod x = y mod n
    if(x == y){
        cout << x << endl;
    }
    else if(x > y){
        cout << x + y << endl;
    }
    else{
        cout << y - y % x / 2 << endl;
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> x >> y;
        solve();
    }
    return 0;
}