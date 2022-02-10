/**
  *@filename:A_Elections
  *@author: pursuit
  *@created: 2021-10-13 22:36
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, a, b, c;
void solve(){
    int res1 = max(b, c), res2 = max(a, c), res3 = max(a, b);
    if(a > res1){
        res1 = 0;
    }
    else{
        res1 = res1 - a + 1;
    }
    if(b > res2){
        res2 = 0;
    }
    else{
        res2 = res2 - b + 1;
    }
    if(c > res3){
        res3 = 0;
    }
    else{
        res3 = res3 - c + 1;
    }
    cout << res1 << " " << res2 << " " << res3 << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> a >> b >> c;
        solve();
    }
    return 0;
}