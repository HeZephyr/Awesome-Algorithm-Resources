/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-13 09:42
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 3e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n;
ll a[N],b[N],c[N];
void solve(){
    ll sum = 0;
    for(int i = 1; i <= n; ++ i){
        sum += c[i];//必须要花费的消耗。
    }
    ll minn = 1e14;
    for(int i = 1; i <= n; ++ i){
        minn = min(minn,a[i] - c[i]);
    }
    printf("%lld\n", sum + minn);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%lld%lld", &a[i], &b[i]);
            if(i > 1)c[i] = a[i] - b[i - 1] < 0 ? 0 : a[i] - b[i - 1];
        }
        c[1] = a[1] - b[n] < 0 ? 0 : a[1] - b[n];
        solve();
    }
    return 0;
}