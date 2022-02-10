/**
  *@filename:Takeway
  *@author: pursuit
  *@created: 2021-09-04 12:21
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

/* 价格达到69，抵扣15，达到89抵扣30，达到120，抵扣50.
7种类型的菜分别为7，27，41，49，63，78，108. */
int t, n, a[10],sum, price[] = {0, 7, 27, 41, 49, 63, 78, 108};
void solve(){
    if(sum >= 120){
        sum -= 50;
    }
    else if(sum >= 89){
        sum -= 30;
    }
    else if(sum >= 69){
        sum -= 15;
    }
    cout << sum << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        sum = 0;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
            sum += price[a[i]];
        }
        solve();
    }
    return 0;
}