/**
  *@filename:A_Consecutive_Sum_Riddle
  *@author: pursuit
  *@created: 2021-10-08 23:05
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
ll l, r, n;
void solve(){
    cout << 1 - n << " " << n << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        solve();
    }
    return 0;
}