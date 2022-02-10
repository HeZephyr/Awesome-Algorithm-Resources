/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-09-09 16:24
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int w1, h1, w2, h2;
void solve(){
    int ans = 2 * w1 + 2 * h1 + 4 + 2 * h2;
    cout << ans << endl;
}
int main(){	
    cin >> w1 >> h1 >> w2 >> h2;
    solve();
    return 0;
}