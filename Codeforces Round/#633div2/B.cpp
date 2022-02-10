/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-14 21:30
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,a[N];
void solve(){
    sort(a + 1, a + 1 + n);
    int l = n / 2,r = n / 2 + 1;
    if(n % 2){
        printf("%d ", a[r ++]);
    }
    while(l >= 1){
        printf("%d %d ",a[l],a[r]);
        l --,r ++;
    }
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