#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, a[N], res[N];
void solve(){
}
int main(){	
    scanf("%d", &n);
    int minn = INF, maxx = 0;
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        minn = min(minn, a[i]);
        maxx = max(maxx, a[i]);
    }
    for(int i = 1; i <= n; ++ i){
        res[i] = floor(100.0 * (a[i] - minn) / (maxx - minn));
        cout << res[i] << " ";
    }
    cout << endl;
    solve();
    return 0;
}