/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-27 10:25
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 100 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,a[N];
void solve(){
    sort(a + 1, a + n + 1);
    //连续的i i + 1 i + 2可以分开。
    int cnt = 1;
    for(int i = 1; i < n; ++ i){
        if(a[i] + 1 == a[i + 1]){
            ++ cnt;
            break;
        }
    }
    cout << cnt << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
        }
        solve();
    }
    return 0;
}