/**
  *@filename:C. Number of Pairs
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-10 22:43
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,n,l,r,a[N];
void solve(){
    ll cnt = 0;
    sort(a + 1,a + 1 + n);
    for(int i = 1; i <= n; ++ i){
        if(a[i] * 2 >= l && a[i] * 2 <= r){
            //说明我们会将自身也算进去。排除这种情况。
            cnt --;
        }
        cnt += upper_bound(a + 1,a + 1 + n,r - a[i]) - lower_bound(a + 1,a + 1 + n,l - a[i]);
    }
    printf("%lld\n",cnt / 2);
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d%d", &n, &l, &r);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}