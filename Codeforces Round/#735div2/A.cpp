/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-09-05 16:44
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N];
int maxx, minn;
ll res;
void solve(){
    printf("%lld\n", res);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        maxx = 0, minn = INF;
        res = 0;
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            res = max(res, 1LL * a[i] * a[i - 1]);
        }
        solve();
    }
    return 0;
}