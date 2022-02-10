/**
  *@filename:I
  *@author: pursuit
  *@created: 2021-08-07 12:04
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int x,s;
void solve(){
    ll ans = 1;
    bool flag = false;
    for(int i = 31; i >= 0; -- i){
        int u = (s >> i) & 1, v = (x >> i) & 1;
        if(u == 0 && v == 1){
            flag = true;
            break;
        }
        else if(u == 1 && v == 1){
            ans *= 2;
        }
    }
    if(x == s)ans -= 1;
    if(flag)ans = 0;
    cout << ans << endl;
}
int main(){
    cin >> x >> s;	
    solve();
    return 0;
}