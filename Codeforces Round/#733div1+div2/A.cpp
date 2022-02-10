/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-10-31 11:36
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
string n;
void solve(){
    int res = 1;
    for(int i = 0; i < n.size(); ++ i){
        res = max(res, n[i] - '0');
    }
    cout << res << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        solve();
    }
    return 0;
}