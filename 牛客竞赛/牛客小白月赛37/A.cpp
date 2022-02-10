/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-27 18:59
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int a,h,b,k;
void solve(){
    //a + b, h - b,k - a;
    int temp1 = (h + b - 1) / b, temp2 = (k + a - 1) / a;
    ll ans = 1LL * min(temp1, temp2) * (a + b);
    if(temp1 != temp2){
        if(temp1 > temp2){
            ans += 1LL * 10 * a;
        }
        else{
            ans += 1LL * 10 * b;
        }
    }
    cout << ans << endl;
}
int main(){	
    cin >> a >> h >> b >> k;
    solve();
    return 0;
}