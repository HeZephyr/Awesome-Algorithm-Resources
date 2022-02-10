/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-28 18:59
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,l1,r1,l2,r2;
void solve(){
    if(l1 != r2){
        cout << l1 << " " << r2 << endl; 
    }
    else{
        cout << r1 << " " << l2 << endl;
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> l1 >> r1 >> l2 >> r2;
        solve();
    }
    return 0;
}