/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-28 21:32
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,k;
void solve(){
    int cnt = 0;
    for(int i = 1; i <= n; ++ i){
        printf("%c", 'a' + (cnt++ % k));
    }
    puts("");
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &k);
        solve();
    }
    return 0;
}