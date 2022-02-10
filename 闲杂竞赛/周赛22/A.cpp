/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-10-26 18:25
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a, b;
void solve(){
    int res = 0;
    for(int i = a; i <= n - 1; ++ i){
        int j = n - i - 1;
        if(j <= b){
            ++ res;
        }
    }
    cout << res << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n >> a >> b;
        solve();
    }
    return 0;
}