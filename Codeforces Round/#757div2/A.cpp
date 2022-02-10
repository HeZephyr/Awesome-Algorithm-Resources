#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N], l, r, k;
void solve(){
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n >> l >> r >> k;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        int cnt = 0;
        for(int i = 1; i <= n; ++ i){
            if(a[i] >= l && a[i] <= r && k >= a[i]){
                ++ cnt;
                k -= a[i];
            }
        }
        cout << cnt << endl;
    }
    solve();
    return 0;
}