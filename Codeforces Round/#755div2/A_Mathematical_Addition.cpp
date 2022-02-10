#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t;
ll u, v;
void solve(){
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> u >> v;
        cout << u * u << " " << v * v * (-1) << endl;
        solve();
    }
    return 0;
}