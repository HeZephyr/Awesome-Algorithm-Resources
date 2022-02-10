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

int t,n,l1,r1,a[N];
void solve(){
    ll cnt = 0;
    sort(a + 1,a + 1 + n);
    int l = 2,r = n;
    while(l <= n && a[l] + a[1] < l1)l ++ ;
    for(int i = 1; i <= n; ++ i){
        while(l > 1 && a[l - 1] + a[i] >= l1)l --;
        while(r > i && a[r] + a[i] > r1)r --;
        if(r >= max(l,i)){
            if(l > i)cnt += r - l + 1;
            else cnt += r - i;
        }
    }
    printf("%lld\n",cnt);
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d%d", &n, &l1, &r1);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}