/**
  *@filename:E
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-20 12:27
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 10000000 + 5;
const int P = 1e9+7;

int t,n;
bool notPrimer[N];
int primer[N];
void init(){
    int cnt = 0;
    for(int i = 2; i < N; ++ i){
        if(!notPrimer[i]){
            //将素数记录
            primer[cnt ++] = i;
        }
        for(int j = 0; j < cnt && primer[j] * i < N; ++ j){
            notPrimer[primer[j] * i] = true;
            if(i % primer[j] == 0)break;
        }
    }
}
void solve(){
    ll ans = 0;
    for(int i = 3; i <= n; ++ i){
        if(notPrimer[i]){
            ans += i;
        }
        else{
            ans += 2 * i;
        }
    }
    printf("%lld\n", ans);
}
int main(){
    scanf("%d", &t);
    init();
    while(t -- ){
        scanf("%d", &n);
        solve();
    }
    return 0;
}