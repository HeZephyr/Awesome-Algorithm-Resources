/**
  *@filename:A_Ezzat_and_Two_Subsequences
  *@author: pursuit
  *@created: 2021-08-09 22:35
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
ll sum;
void solve(){
    sort(a + 1,a + 1 + n);
    printf("%.8f\n", 1.0 * (sum - a[n]) / (n - 1) + a[n]);
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