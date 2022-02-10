/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-09-05 16:51
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, k, a[N];
void solve(){
    ll res = -1e12;
    for(int i = n; i >= max(1, n - 200); -- i){
        for(int j = i - 1; j >= max(1, n - 200); -- j){
            res = max(res, 1LL * i * j - 1LL * k * (a[i] | a[j]));
        }
    }
    printf("%lld\n", res);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}