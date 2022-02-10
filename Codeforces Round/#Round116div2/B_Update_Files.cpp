/**
  *@filename:B_Update_Files
  *@author: pursuit
  *@created: 2021-10-29 22:55
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
ll k, n;
void solve(){
    ll cnt = 0;
    ll ans = 1;
    while(ans < n){
        if(k > ans){
            ans *= 2;
            ++ cnt;
        }
        else{
            ll temp = (n - ans) / k + ((n - ans) % k != 0);
            cnt += temp;
            break;
        }
    }
    cout << cnt << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n >> k;
        
        solve();
    }
    return 0;
}