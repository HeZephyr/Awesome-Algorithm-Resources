/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-25 22:57
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
ll n;
bool check(ll n){
    ll temp = n;
    while(temp > 0){
        if(temp % 10 && n % (temp % 10) != 0){
            return false;
        }
        temp /= 10;
    }
    return true;
}
void solve(){
    while(true){
        if(check(n)){
            printf("%lld\n", n);
            break;
        }
        ++ n;
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        solve();
    }
    return 0;
}