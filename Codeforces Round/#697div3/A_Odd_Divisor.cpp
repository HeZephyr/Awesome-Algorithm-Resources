/**
  *@filename:A_Odd_Divisor
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-08 09:15
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
ll n;       
void solve(){
    while(n % 2 == 0)n /= 2;
    if(n > 1){
        puts("YES");
    }
    else{
        puts("NO");
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        solve();
    }
    return 0;
}