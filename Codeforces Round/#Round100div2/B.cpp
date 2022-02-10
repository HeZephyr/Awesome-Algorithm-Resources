/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-17 09:32
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 50 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,a[N],b[N];
ll sum;
void solve(){
    ll sum1 = 0;
    for(int i = 1; i <= n; ++ i){
        if(i & 1){
            b[i] = 1;
        }
        else{
            b[i] = a[i];
        }
        sum1 += 1LL * (a[i] - b[i]);
    }
    if(sum1 * 2 <= sum){
        for(int i = 1; i <= n; ++ i){
            printf("%d ", b[i]);
        }
    }
    else{
        for(int i = 1; i <= n; ++ i){
            printf("%d ", (i & 1) ? a[i] : 1);
        }
    }
    puts("");
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        sum = 0;
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        solve();
    }
    return 0;
}