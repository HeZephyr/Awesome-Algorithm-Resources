#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

ll n, l, r;
void solve(){
    ll temp1 = r / n, temp2 = l / n;
    if(temp1 > temp2){
        cout << n - 1 << endl;
    }
    else{
        cout << r % n << endl;
    }
}
int main(){	
    cin >> n >> l >> r;
    solve();
    return 0;
}