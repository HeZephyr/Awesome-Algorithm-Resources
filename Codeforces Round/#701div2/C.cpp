/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-09-07 09:49
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, x, y;
void solve(){
    int temp = sqrt(x);
    ll sum = 0;
    for(int k = 1; k <= temp; ++ k){
        //- k是因为b > k。
        sum += max(0, min(y, x / k - 1) - k);
    }
    printf("%lld\n", sum);
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> x >> y;
        solve();
    }
    return 0;
}