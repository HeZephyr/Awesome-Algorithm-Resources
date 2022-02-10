/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-08-12 15:28
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m,k,x;
int a[N],maxx;
ll cnt;
void solve(){
    ll ans = 0;
    for(int i = i; i <= maxx; ++ i){
        if(i < m)cnt += a[i];
        else cnt += (a[i] - a[i - m]);
        if(cnt >= k){
            ans += cnt - k + 1;
            a[i] -= (cnt - k + 1);
            cnt = k - 1;
        }
        //cout << cnt << endl;
    }
    printf("%lld\n", ans);
}
int main(){	
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &x);
        maxx = max(maxx,x);
        a[x] ++;
    }
    solve();
    return 0;
}