/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-10-16 21:55
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N], b[N];
void solve(){
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &b[i]);
        }
        if(a[1] < b[1]){
            puts("0");
        }
        else{
            int ans = 1;
            for(int i = 2; i <= n; ++ i){
                if(a[i] > b[1])++ ans;
                else break;
            }
            int cnt = 1;
            for(int i = 2; i <= n; ++ i){
                if(a[1] > b[i])++ cnt;
                else break;
            }
            ans = min(ans, cnt);
            cout << ans << endl;
        }
        solve();
    }
    return 0;
}