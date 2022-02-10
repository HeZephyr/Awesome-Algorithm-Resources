/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-09-14 09:17
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 100 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N];
void solve(){
    int cnt = 0, sum = 0;
    for(int i = 1; i <= n; ++ i){
        if(a[i] == 0){
            ++ cnt;
            ++ a[i];
        }
        sum += a[i];
    }
    if(sum == 0)++ cnt;
    printf("%d\n", cnt);
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