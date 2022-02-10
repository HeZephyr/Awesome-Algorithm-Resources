#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, a[N];
void solve(){
    ll cnt = 0;
    for(int i = 2; i <= n; ++ i){
        cnt += max(a[i - 1], a[i]);
    }
    printf("%lld\n", cnt);
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}