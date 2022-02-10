/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-10-14 21:18
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N], H;
void solve(){
    sort(a + 1, a + 1 + n);
    int cnt = H / (a[n] + a[n - 1]) * 2;
    H %= (a[n] + a[n - 1]);
    if(H > a[n]){
        cnt += 2;
    }
    else if(H > 0){
        cnt += 1;
    }
    cout << cnt << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n >> H;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
        }
        solve();
    }
    return 0;
}