/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-09-01 10:19
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
//经验值为a的人只能加入a或者更多人的群组。
void solve(){
    sort(a + 1, a + 1 + n);
    int res = 0, cnt = 0;
    for(int i = 1; i <= n; ++ i){
        ++ cnt;
        if(a[i] <= cnt){
            ++ res;
            cnt = 0;
        }
    }
    printf("%d\n", res);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}