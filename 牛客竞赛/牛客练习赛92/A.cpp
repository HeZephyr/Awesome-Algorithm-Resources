#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
ll a, b, c[N];
void solve(){
    ll sum = b * n;
    for(int i = 1; i <= n / 2; ++ i){
        c[i] = -1 * 2e6;
    }
    for(int i = n / 2 + 1; i <= n - 1; ++ i){
        c[i] = a;
    }
    c[n] = sum + 2e6 * (n / 2) - a * (n / 2);
    if(c[n] < a){
        cout << - 1 << endl;
        return;
    }
    for(int i = 1; i <= n; ++ i){
        cout << c[i] << " ";
    }
    cout << endl;
}
int main(){	
    cin >> n >> a >> b;
    solve();
    return 0;
}