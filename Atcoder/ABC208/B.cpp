/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-04 20:03
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int p;
int fac[11];
void solve(){
    fac[0] = fac[1] = 1;
    for(int i = 2; i <= 10; ++ i){
        fac[i] = fac[i - 1] * i;
    }
    int ans = 0,i = 10;
    while(p > 0){
        if(p < fac[i]){
            i --;
        }
        else{
            p -= fac[i];
            ans ++;
        }
    }
    cout << ans << endl;
}
int main(){
    cin >> p;
    solve();
    return 0;
}