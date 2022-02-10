#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, xa, ya, xb, yb, xp, yp;
void solve(){
    int res = int(abs(xa - xb) + abs(ya - yb));
    if(xa == xb && xp == xa && yp >= min(ya, yb) && yp <= max(ya, yb)){
        res += 2;
    }
    else if(ya == yb && yp == ya && xp >= min(xa, xb) && xp <= max(xa, xb)){
        res += 2;
    }
    cout << res << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> xa >> ya >> xb >> yb >> xp >> yp;
        solve();
    }
    return 0;
}