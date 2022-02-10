/**
  *@filename:B_Pleasant_Pairs
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-25 23:48
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,a[N];
map<int,int> p;
void solve(){
    ll cnt = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j * a[i] <= 2 * n; ++ j){
            if(p[j] == 0)continue;
        }
        p[a[i]] = i;
    }
    printf("%lld\n",cnt);
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        p.clear();
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}