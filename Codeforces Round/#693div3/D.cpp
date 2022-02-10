/**
  *@filename:D
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-10 08:46
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,n,a[N];
void solve(){
    sort(a + 1,a + 1 + n,greater<int>() );
    ll cnt1 = 0,cnt2 = 0;
    for(int i = 1; i <= n; ++ i){
        if((i & 1) && (a[i] % 2 == 0)){
            cnt1 += a[i];
        }
        else if((i % 2 == 0) && (a[i] & 1)){
            cnt2 += a[i];
        }
    }
    if(cnt1 > cnt2){
        puts("Alice");
    }
    else if(cnt1 == cnt2){
        puts("Tie");
    }
    else{
        puts("Bob");
    }
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