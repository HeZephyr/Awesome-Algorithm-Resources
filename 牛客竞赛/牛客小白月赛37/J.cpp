/**
  *@filename:J
  *@author: pursuit
  *@created: 2021-08-27 19:02
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

string s;
void solve(){
    cout << s.substr(0,s.size() - 3) << endl;
}
int main(){	
    getline(cin, s);
    solve();
    return 0;
}