/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-09 17:28
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,a[N],pos[N];
void solve(){
    int r = 0,l = n + 1;
    for(int i = 1; i <= n; ++ i){
        r = max(r,pos[i]);
        l = min(l,pos[i]);
        printf("%d", r - l + 1 == i);
    }
    puts("");
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            pos[a[i]] = i;//记录下标。
        }
        solve();
    }
    return 0;
}