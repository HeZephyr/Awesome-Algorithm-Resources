/**
  *@filename:C_Delete_Two_Elements
  *@author: pursuit
  *@created: 2021-10-10 17:35
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
ll sum;
void solve(){
    if(2 * sum % n != 0){
        puts("0");
    }
    else{
        map<int, int> p;
        ll x = 2 * sum / n, res = 0;
        for(int i = 1; i <= n; ++ i){
            res += p[x - a[i]];
            ++ p[a[i]];
        }
        printf("%lld\n", res);
    }
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