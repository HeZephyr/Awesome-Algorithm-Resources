/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-09-14 09:21
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N];
void solve(){
    sort(a + 1, a + 1 + 2 * n);
    cout << a[n + 1] - a[n] << endl;
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= 2 * n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}