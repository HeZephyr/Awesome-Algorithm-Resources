/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-09-01 10:13
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t;
ll a, k;
ll cal(ll a){
    ll minn = INF, maxx = 0;
    while(a){
        minn = min(a % 10, minn);
        maxx = max(a % 10, maxx);
        a /= 10;
    }
    return minn * maxx;
}
void solve(){
    int i = 1;
    while(i < k){
        ll temp = cal(a);
        if(temp == 0)break;
        a += temp;
        ++ i;
    }
    printf("%lld\n", a);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%lld%lld", &a, &k);
        solve();
    }
    return 0;
}