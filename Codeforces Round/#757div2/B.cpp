#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N], pos[N], res[N];
bool cmp(int i, int j){
    return a[i] < a[j];
}
void solve(){
    sort(pos + 1, pos + 1 + n, cmp);
    for(int i = 1; i <= n; ++ i){
        res[i] = n - i + 1;
    }
    int l = -1, r = 1;
    ll ans = 0;
    for(int i = n; i >= 1; -- i){
        int id = pos[i];
        if(abs(l) > abs(r)){
            res[id] = r;
            ans += 2LL * r * a[id];
            ++ r;
        }
        else{
            ans -= 2LL * l * a[id];
            res[id] = l;
            -- l;
        }
    }
    cout << ans << endl;
    for(int i = 0; i <= n; ++ i){
        cout << res[i] << " ";
    }
    cout << endl;
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            pos[i] = i;
        }
        solve();
    }
    return 0;
}