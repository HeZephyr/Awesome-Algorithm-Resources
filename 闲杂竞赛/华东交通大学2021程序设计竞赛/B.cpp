#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, a[N], f[N];
void solve(){
    int res = 0;
    for(int i = 1; i <= n; ++ i){
        int n1 = 0, n2 = 0;
        memset(f, 0, sizeof(f));
        for(int j = 1; j < i; ++ j){
            if(a[j] > a[i])continue;
            if(a[j] >= f[n1]){
                f[++ n1] = a[j];
            }
            else{
                int x = lower_bound(f + 1, f + 1 + n1, a[j]) - f;
                f[x] = a[j];
            }
        }
        memset(f, 0, sizeof(f));
        for(int j = n; j > i; -- j){
            if(a[j] > a[i])continue;
            if(a[j] >= f[n2]){
                f[++ n2] = a[j];
            }
            else{
                int x = lower_bound(f + 1, f + 1 + n2, a[j]) - f;
                f[x] = a[j];
            }
        }
        res = max(res, n1 + n2 + 1);
    }
    printf("%d\n", n - res);
}
int main(){	
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
    }
    solve();
    return 0;
}