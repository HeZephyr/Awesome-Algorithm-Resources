#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;


int t, a, p;
void solve(){
    if(p >= 16 && p <= 20){
        cout << a << endl;
    }
    else if(p < 16){
        cout << max(0, a - 10) << endl;
    }
    else{
        cout << max(0, a - (p - 20)) << endl;
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> a >> p;
        solve();
    }
    return 0;
}