/**
  *@filename:Easy_Math_Problem
  *@author: pursuit
  *@created: 2021-09-04 12:05
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
ll p;
void solve(){
    cout << 12 * p << " " << 3 << endl;
    cout << 2 * p << " " << 4 * p << " " << 6 * p << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> p;
        solve();
    }
    return 0;
}