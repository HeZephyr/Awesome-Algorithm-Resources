/**
  *@filename:E1
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-09 15:15
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,n,a[N];
map<int,int> p;
void solve(){
    ll sum = 0;
    for(int i = 1; i <= n; ++ i){
        p[a[i]] ++;
        if(p[a[i]] >= 3){
            //就可以构成3个a[i];
        }
    }
    printf("%lld\n",sum);
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