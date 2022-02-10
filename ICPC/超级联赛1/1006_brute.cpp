/**
  *@filename:1006_brute
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-20 20:32
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,k,a[N];
void solve(){
    int l = -1,r = n;
    for(int i = 1; i <= n; ++ i){
        int x = 0;
        for(int j = i; j <= n; ++ j){
            x ^= a[j];
            if(j - i >= r - l)break;
            if(x >= k){
                //说明符合条件。
                l = i, r = j;
            }
        }
    }
    printf("%d %d\n", l, r);
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}