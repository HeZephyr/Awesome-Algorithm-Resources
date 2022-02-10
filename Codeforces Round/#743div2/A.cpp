/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-10-16 21:50
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n;
string s;
void solve(){
    int res = 0;
    for(int i = 0; i < n; ++ i){
        res += (s[i] - '0');
        if((s[i] - '0' > 0) && i != n - 1)++ res;
    }
    cout << res << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n >> s;
        solve();
    }
    return 0;
}