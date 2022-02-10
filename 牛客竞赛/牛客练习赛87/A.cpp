/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-20 19:00
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,k;
ll a[N];
void solve(){
    sort(a + 1, a + 1 + n);
    int l = n;
    while(k > 0){
        a[l - 1] += a[l];
        l --, k --;
    }
    printf("%lld\n", a[(l + 1) / 2]);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++ i){
            scanf("%lld", &a[i]);
        }
        solve();
    }
    return 0;
}