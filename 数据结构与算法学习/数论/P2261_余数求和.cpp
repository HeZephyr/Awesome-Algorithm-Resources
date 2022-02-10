/**
  *@filename:P2261_余数求和
  *@author: pursuit
  *@created: 2021-09-14 15:36
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, k;
void solve(){
    ll res = 1LL * n * k;
    for(int l = 1, r; l <= n; l = r + 1){
        if(k / l != 0){
            r = min(k / (k / l), n);
        }
        else{
            r = n;
        }
        res -= 1LL * (k / l) * (r - l + 1) * (l + r) / 2;
    }
    cout << res << endl;
}
int main(){	
    cin >> n >> k;
    solve();
    return 0;
}