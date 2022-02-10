/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-09-09 16:28
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e4 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, a[N], b[N];
void solve(){
    ll ans = 0;
    for(int i = 1; i <= n; ++ i){
        ans += max(0, min(a[i], b[i]) - max(a[i - 1], b[i - 1]) + 1);
        if(a[i] == b[i]){
            //该点已经被计算过。
            ++ a[i];
        }
    }
    printf("%lld\n", ans);
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d%d", &a[i], &b[i]);
    }
    solve();
    return 0;
}