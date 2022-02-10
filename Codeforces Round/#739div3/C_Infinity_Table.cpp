/**
  *@filename:C_Infinity_Table
  *@author: pursuit
  *@created: 2021-08-18 22:56
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,k;
void solve(){
    int x = 1;
    while(k > 2 * (x - 1) + 1){
        k -= 2 * (x - 1) + 1;
        x ++;
    }
    if(k <= x){
        cout << k << " " << x << endl;
    }
    else{
        cout << x << " " << 2 * x - k << endl;
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> k;
        solve();
    }
    return 0;
}