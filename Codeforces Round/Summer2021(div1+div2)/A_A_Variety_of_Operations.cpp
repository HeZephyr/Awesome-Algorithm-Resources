/**
  *@filename:A_A_Variety_of_Operations
  *@author: pursuit
  *@created: 2021-08-29 22:35
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,a,b,c,d;
void solve(){
    if((c + d) % 2){
        cout << - 1 << endl;
    }
    else if(c == d){
        cout << (c != 0) << endl;
    }
    else{
        cout << 2 << endl;
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> c >> d;
        solve();
    }
    return 0;
}