/**
  *@filename:C_Minimum_Extraction
  *@author: pursuit
  *@created: 2021-11-02 22:48
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n;
ll a[N];
void solve(){
    priority_queue<ll,vector<ll>, greater<ll> > q;
    for(int i = 1; i <= n; ++ i)q.push(a[i]);
    ll ans = 0, res = 0;
    while(!q.empty()){
        ll x = q.top();
        q.pop();
        x += ans;
        if(x > 0 || q.empty()){
            res = x;
            ans -= x;
            break;
        }
        ans -= x;
    }
    while(!q.empty()){
        ll x = q.top();
        q.pop();
        x += ans;
        res = max(res, x);
        ans -= x;
    }
    printf("%lld\n", res);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%lld", &a[i]);
        }
        solve();
    }
    return 0;
}