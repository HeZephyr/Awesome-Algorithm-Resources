#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, p, a[N];
void solve(){
    sort(a + 1, a + n + 1);
    int maxx = 0;
    int l = 1, r = 1;
    while(r <= n){
        while(r <= n && a[r] - a[l] <= 2 * p){
            ++ r;
        }
        maxx = max(maxx, r - l);
        ++ l;
    }
    printf("%d\n", maxx);
}
int main(){	
    scanf("%d%d", &n, &p);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}