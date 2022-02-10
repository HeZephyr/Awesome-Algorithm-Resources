/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-11 19:04
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m;
ll a[N],b[N],sum[N];
void solve(){
    for(int i = 1; i <= m; ++ i){
        int idx = lower_bound(sum + 1,sum + 1 + n,b[i]) - sum;
        printf("%d %lld\n", idx,b[i] - sum[idx - 1]);
    }
}
int main(){	
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    for(int i = 1; i <= m; ++ i){
        scanf("%lld", &b[i]);
    }
    solve();
    return 0;
}