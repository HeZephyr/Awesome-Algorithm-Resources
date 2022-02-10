#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
ll a[N];
void solve(){
    int l = 1, r = 1;//r为最远到达的点。
    while(l <= r){
        r = min(1LL * n, max(r * 1LL, l + a[l]));
        ++ l;
    }
    cout << r << endl;
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
    }
    solve();
    return 0;
}