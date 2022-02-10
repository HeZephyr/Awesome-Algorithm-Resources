#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t;
ll a, b;
void solve(){
    if(a < b)swap(a, b);
    if(a >= 3 * b){
        cout << b << endl;
    }
    else{
        cout << (a + b) / 4 << endl;
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> a >> b;
        solve();
    }
    return 0;
}