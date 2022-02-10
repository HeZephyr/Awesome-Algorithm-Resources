/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-21 19:00
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,k;
void solve(){
    if(n > 2 && k == n){
        cout << "Yes!" << endl; 
    }
    else if(n == 1){
        cout << "No!" << endl;
    }
    else{
        if(k % 2 == 0){
            cout << "No!" << endl;
        }
        else{
            cout << "Yes!" << endl;
        }
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n >> k;
        solve();
    }
    return 0;
}
