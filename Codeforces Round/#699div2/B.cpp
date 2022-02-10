/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-09-12 10:46
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, k, h[N];
void solve(){
    //小于的话就会一直滚动过去。
    bool flag = false;
    int res;
    while(k -- ){
        for(int i = 1; i <= n; ++ i){
            if(i == n){
                flag = true;
                break;
            }
            if(h[i] < h[i + 1]){
                res = i;
                ++ h[i];
                break;
            }
        }
        if(flag)break;
    }
    if(flag)puts("-1");
    else printf("%d\n", res);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &h[i]);
        }
        solve();
    }
    return 0;
}