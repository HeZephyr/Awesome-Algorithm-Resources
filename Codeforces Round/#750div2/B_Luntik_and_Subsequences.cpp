/**
  *@filename:B_Luntik_and_Subsequences
  *@author: pursuit
  *@created: 2021-10-24 18:30
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 60 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N];
ll res;
void solve(){
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        int cnt0 = 0, cnt1 = 0;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
            if(a[i] == 0)++ cnt0;
            if(a[i] == 1)++ cnt1;
        }
        res = pow(2, cnt0);
        cout << res * cnt1 << endl;
        solve();
    }
    return 0;
}