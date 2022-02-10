/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-10 18:45
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,a[N];
map<ll,int> p;
void solve(){
    ll ans = 0, sum = 0;
    int pos = -1;//为最早不好的。
    p[0] = 0;
    for(int i = 1; i <= n; ++ i){
        sum += a[i];
        if(p.count(sum)){
            pos = max(pos,p[sum]);
        }
        ans += i - (pos + 1);
        p[sum] = i;
    }
    cout << ans << endl;
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}