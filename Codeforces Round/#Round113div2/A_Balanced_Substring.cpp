/**
  *@filename:A_Balanced_Substring
  *@author: pursuit
  *@created: 2021-09-08 22:35
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
char s[N];
void solve(){
    for(int i = 1; i < n; ++ i){
        if(s[i] != s[i + 1]){
            cout << i << " " << i + 1 << endl;
            return;
        }
    }
    cout << -1 << " " << -1 << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n >> s + 1;
        solve();
    }
    return 0;
}