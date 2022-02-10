/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-09-11 10:30
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//a1 = -1, 则n * s - (n - 1) * (s + 1) = s - n + 1 = k
int k, n = 2000;
void solve(){
    cout << n << endl;
    int s = k + n;
    cout << -1 << " ";
    int i, x = 1e6;
    for(i = 2; i <= n; ++ i){
        if(s > x){
            cout << x << " ";
            s -= x;
        }
        else{
            cout << s << " ";
            ++ i;
            break;
        }
    }
    while(i ++ <= n){
        cout << 0 << " ";
    }
    cout << endl;
}
int main(){	
    cin >> k;
    solve();
    return 0;
}