#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, m, x, a[N], ok[N];
void solve(){
    while(m -- ){
        scanf("%d", &x);
        printf("%s\n", (ok[x] == x) ? "YES" : "NO");
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++ i)ok[i] = 0, a[i] = 0;
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &x);
            ++ a[x];
        }
        for(int i = 1; i <= n; ++ i){
            for(int j = i; j <= n; j += i){
                if(a[j])ok[i] = gcd(ok[i], j);
            }
        }
        solve();
    }
    return 0;
}