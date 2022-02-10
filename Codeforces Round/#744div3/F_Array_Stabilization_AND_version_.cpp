/**
  *@filename:F_Array_Stabilization_AND_version_
  *@author: pursuit
  *@created: 2021-09-29 17:17
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//
int t, n, d, a[N];
pii q[N];
int st, ed;
void solve(){
    st = 1, ed = 0;
    int res = 0;
    for(int i = 0; i < n; ++ i){
        if(!a[i])q[++ ed] = {0, i};
    }
    while(st <= ed){
        auto x = q[st ++];
        int u = (x.second + d) % n;
        if(a[u]){
            a[u] = 0;
            q[++ ed] = {x.first + 1, u};
            res = max(res, x.first + 1);
        }
    }
    for(int i = 0; i < n; ++ i){
        if(a[i]){
            res = -1;
            break;
        }
    }
    printf("%d\n", res);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &d);
        for(int i = 0; i < n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}