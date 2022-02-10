/**
  *@filename:线性基
  *@author: pursuit
  *@created: 2021-10-16 10:17
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 60 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
ll p[N], x;
void get(ll x){
    for(int i = 62; i >= 0; -- i){
        int u = (x >> i) & 1;
        if(!u)continue;
        if(!p[i]){
            p[i] = x;
            break;
        }
        x ^= p[i];
    }
}
void solve(){
    ll ans = 0;
    for(int i = 62; i >= 0; -- i){
        if((p[i] ^ ans) > ans)ans ^= p[i];
    }
    cout << ans << endl;
}
int main(){	
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> x;
        get(x);
    }
    solve();
    return 0;
}