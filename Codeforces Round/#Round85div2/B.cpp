/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-13 09:35
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,x,a[N];
void solve(){
    sort(a + 1, a + n + 1);
    ll sum = 0;
    int cnt = 0;
    for(int i = n; i >= 1; -- i){
        sum += a[i];
        cnt ++;
        if(1.0 * sum / cnt < x){
            cnt --;
            break;
        }
    }
    printf("%d\n", cnt);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &x);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}