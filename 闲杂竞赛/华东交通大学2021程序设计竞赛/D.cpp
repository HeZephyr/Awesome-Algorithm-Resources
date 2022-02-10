#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, t[N], w[N];
void solve(){
}
int main(){	
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; ++ i){
        cin >> t[i] >> w[i];
        sum += w[i];
    }
    cout << sum * 3 << endl;
    solve();
    return 0;
}