#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int h, e, t;
void solve(){
}
int main(){	
    cin >> t >> h >> e;
    int temp = floor(0.2 * t + 0.3 * h + 0.5 * e);
    cout << temp << endl;
    solve();
    return 0;
}