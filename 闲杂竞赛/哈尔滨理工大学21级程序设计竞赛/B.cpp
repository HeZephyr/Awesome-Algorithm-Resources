#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

ll a, n;
void solve(){
    // a元。
    if(a >= 5 * n){
        cout << n << " " << a - 5 * n << endl;
    }
    else{
        cout << a / 5 << " " <<  a % 5 << endl;
    }
}
int main(){	
    cin >> n >> a;
    solve();
    return 0;
}