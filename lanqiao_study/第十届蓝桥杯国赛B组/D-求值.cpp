/**
  *@filename:D-求值
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-04 17:49
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int cal(int n){
    int ans = 0;
    for(int i = 1; i <= n; ++ i){
        if(n % i == 0)ans ++;
    }
    return ans;
}
void solve(){
    for(int i = 1;; ++ i){
        if(cal(i) == 100){
            printf("%d\n",i);//45360
            break;
        }
    }
}
int main(){
    solve();
    return 0;
}