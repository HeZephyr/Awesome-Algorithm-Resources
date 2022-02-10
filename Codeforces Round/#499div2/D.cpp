/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-10-27 20:24
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m, k;
void solve(){
}
int main(){	
    scanf("%d%d", &n, &k);
    int gcd = k;
    for(int i = 1, x; i <= n; ++ i){
        scanf("%d", &x);
        gcd = __gcd(gcd, x);
    }
    printf("%d\n", k / gcd);
    for(int i = 0; i < k / gcd; ++ i){
        printf("%d ", i * gcd);
    }
    puts("");
    solve();
    return 0;
}