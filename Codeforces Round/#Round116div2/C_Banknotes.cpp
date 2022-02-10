/**
  *@filename:C_Banknotes
  *@author: pursuit
  *@created: 2021-10-29 23:14
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n;
ll k;
ll a[12];
void solve(){
    ++ k;
    if(n == 1){
        printf("%lld\n", k);
        return;
    }
    ll ans = 0;
    for(int i = 1; i < n; ++ i){
        ll temp = a[i + 1] - a[i];//a[i]能表示的最大数。需要花费temp / a[i]次。
        if(k >= temp / a[i]){
            ans += temp;
            k -= (temp / a[i]);
        }
        else{
            ans += k * a[i];
            k = 0;
            break;
        }
    }
    if(k > 0){
        ans += k * a[n];
    }
    printf("%lld\n", ans);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%lld", &n, &k);
        for(int i = 1; i <= n; ++ i){
            scanf("%lld", &a[i]);
            a[i] = pow(10, a[i]);
        }
        solve();
    }
    return 0;
}