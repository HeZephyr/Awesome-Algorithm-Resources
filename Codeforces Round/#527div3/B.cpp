/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-29 14:03
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,a[N];
void solve(){
    sort(a + 1, a + n + 1);
    int ans = 0;
    for(int i = 2; i <= n; i += 2){
        ans += a[i] - a[i - 1];
    }
    printf("%d\n", ans);
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}