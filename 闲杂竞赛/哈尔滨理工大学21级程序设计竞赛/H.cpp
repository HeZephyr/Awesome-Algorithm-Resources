#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int l, n, x[N];
void solve(){
    int minn = 0, maxx = 0;
    for(int i = 1; i <= n; ++ i){
        minn = max(minn, min(x[i], l - x[i]));
        maxx = max(maxx, max(x[i], l - x[i]));
    }
    printf("%d %d\n", minn, maxx);
}
int main(){	
    scanf("%d%d", &l, &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &x[i]);
    }
    solve();
    return 0;
}