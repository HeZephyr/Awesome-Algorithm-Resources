/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-08-13 12:40
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n;
ll l,r;
ll pre[N];
int cal(ll x){
    if(x > pre[n - 1])return 1;//排除特殊情况。
    int idx = lower_bound(pre + 1,pre + n + 1,x) - pre;
    //那么pre就在idx所管辖的这个区间为 idx idx + 1 idx idx + 2...这种形式。
    x = x - pre[idx - 1];
    return x & 1 ? idx : x / 2 + idx;
}
void solve(){
    for(int i = 1; i <= n; ++ i){
        pre[i] = pre[i - 1] + 2 * (n - i);
    }
    for(ll i = l; i <= r; ++ i){
        printf("%d%c", cal(i), " \n"[i == r]);
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%lld%lld", &n, &l, &r);
        solve();
    }
    return 0;
}