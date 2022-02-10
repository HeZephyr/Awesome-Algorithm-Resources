/**
  *@filename:C_Carrying_Conundrum
  *@author: pursuit
  *@created: 2021-09-05 22:57
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[12], len;
ll res;
void solve(){
    len = 0;
    int temp = n;
    while(temp){
        a[++ len] = temp % 10;
        temp /= 10;
    }
    ll ans1 = 0, ans2 = 0;
    for(int i = len; i >= 1; -- i){
        if(i & 1){
            ans2 = ans2 * 10 + a[i];
        }
        else{
            ans1 = ans1 * 10 + a[i];
        }
    }
    cout << (ans1 + 1) * (ans2 + 1) - 2 << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        solve();
    }
    return 0;
}