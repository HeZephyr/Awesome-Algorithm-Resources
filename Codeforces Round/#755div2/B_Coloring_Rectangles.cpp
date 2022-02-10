#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, m;
void solve(){
    cout << (n * m + 2) / 3 << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n >> m;
        solve();
    }
    return 0;
}