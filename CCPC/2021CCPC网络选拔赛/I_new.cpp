/**
  *@filename:I
  *@author: pursuit
  *@created: 2021-08-28 12:07
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n;
char s[N];
void solve(){
    map<pii,int> p;
    pii cur(0,0);
    p[cur] ++;
    for(int i = 1; i <= n; ++ i){
        if(s[i] == 'R'){
            cur.second += 1; 
        }
        else if(s[i] == 'L'){
            cur.second -= 1;
        }
        else if(s[i] == 'U'){
            cur.first -= 1;
        }
        else{
            cur.first += 1;
        }
        ++ p[cur];
    }
    cur = pii(0,0);
    ll ans = 0;
    for(auto &x : p){
        if(x.second > 1){
            ans += 1LL * x.second * (x.second - 1) / 2;
        }
    }
    cout << ans << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        //cin >> n >> s + 1;
        cin >> n >> s + 1;
        solve();
    }
    return 0;
}