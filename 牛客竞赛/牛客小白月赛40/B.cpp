#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 4e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, a[N];
int f[N][N];
void solve(){
    for(int len = 2; len <= n; ++ len){
        for(int l = 1; l + len - 1 <= 2 * n; ++ l){
            int r = l + len - 1;
            f[l][r] = max(f[l][r], max(f[l + 1][r] + len * a[l], f[l][r - 1] + len * a[r]));
        }
    }
    int maxx = 0;
    for(int i = 1; i <= n; ++ i){
        maxx = max(maxx, f[i][i + n - 1]);
    }
    printf("%d\n", maxx);
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        a[i + n] = a[i];
        f[i][i] = f[i + n][i + n] = a[i];
    }
    solve();
    return 0;
}