/**
  *@filename:C_Di_visible_Confusion
  *@author: pursuit
  *@created: 2021-10-30 22:58
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n;
ll a[N];
void solve(){
    bool flag = true;
    ll ans = 1;
    for(ll i = 1; i <= n; ++ i){
        ans = ans * (i + 1) / __gcd(ans, i + 1);
        if(a[i] % ans == 0){
            flag = false;
            break;
        }
    }
    if(!flag)puts("NO");
    else puts("YES");
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