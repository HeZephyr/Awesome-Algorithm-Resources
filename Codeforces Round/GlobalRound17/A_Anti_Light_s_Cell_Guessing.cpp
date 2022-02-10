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

}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n >> m;
        int temp = min(n, m);
        if(temp > 1)temp = 2;
        else if(n == 1 && m == 1)temp = 0;
        cout << temp << endl;
        solve();
    }
    return 0;
}