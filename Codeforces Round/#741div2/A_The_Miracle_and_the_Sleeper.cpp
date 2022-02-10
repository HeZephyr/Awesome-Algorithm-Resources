/**
  *@filename:A_The_Miracle_and_the_Sleeper
  *@author: pursuit
  *@created: 2021-08-26 22:35
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,l,r;
//l <= b <= a <= r
void solve(){
    int x = max(l, r / 2 + 1);
    cout << r % x << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> l >> r;
        solve();
    }
    return 0;
}