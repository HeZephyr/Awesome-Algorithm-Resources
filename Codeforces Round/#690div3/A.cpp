/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-09 14:09
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,a[N];
void solve(){
    int l = 1,r = n;
    while(l <= r){
        printf("%d ", a[l]);
        l ++;
        if(l > r)break;
        printf("%d ", a[r]);
        r --;
    }
    puts("");
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