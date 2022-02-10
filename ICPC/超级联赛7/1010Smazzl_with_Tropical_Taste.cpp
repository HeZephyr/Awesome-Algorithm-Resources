/**
  *@filename:1010Smazzl_with_Tropical_Taste
  *@author: pursuit
  *@created: 2021-08-10 12:10
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
double p,q;
void solve(){
    if(p <= q){
        cout << "N0 M0R3 BL4CK 1CE TEA!" << endl;
    }
    else{
        cout << "ENJ0Y YOURS3LF!" << endl;
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> p >> q;
        solve();
    }	
    return 0;
}