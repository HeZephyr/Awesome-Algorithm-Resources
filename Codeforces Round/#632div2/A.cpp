/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-10 18:18
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,m;
void solve(){
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            if(i == n && j == m)cout << 'W';
            else cout << 'B';
        }
        cout << endl;
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n >> m;
        solve();
    }
    return 0;
}