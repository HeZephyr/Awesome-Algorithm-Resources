/**
  *@filename:A_Era
  *@author: pursuit
  *@created: 2021-10-30 22:36
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N];
void solve(){
    ll res = 0;
    for(int i = 1; i <= n; ++ i){
        if(a[i] > i + res){
            res = a[i] - i;
        }
    }
    cout << res << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
        }
        solve();
    }
    return 0;
}