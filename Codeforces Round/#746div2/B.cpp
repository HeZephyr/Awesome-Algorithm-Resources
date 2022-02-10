/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-10-14 21:22
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, x, a[N], b[N];
void solve(){
    if(2 * x <= n){
        puts("YES");
    }
    else{
        sort(a + 1, a + n + 1);
        bool flag = false;
        for(int i = n - x + 1; i <= x; ++ i){
            if(a[i] != b[i]){
                flag = true;
                break;
            }
        }
        if(flag)puts("NO");
        else puts("YES");
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &x);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        solve();
    }
    return 0;
}