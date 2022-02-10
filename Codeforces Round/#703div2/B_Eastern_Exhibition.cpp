/**
  *@filename:B_Eastern_Exhibition
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-04 19:26
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 10000 + 5;
const int P = 1e9+7;

int t,n;
ll a[N],b[N];
void solve(){
    if(n & 1){
        printf("1\n");
    }
    else{
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);
        printf("%lld\n", (a[n / 2 + 1] - a[n / 2] + 1) * (b[n / 2 + 1] - b[n / 2] + 1));
    }
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%lld%lld", &a[i], &b[i]);
        }
        solve();
    }
    return 0;
}