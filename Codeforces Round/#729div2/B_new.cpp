/**
  *@filename:B_Plus_and_Multiply
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-03 21:08
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,a,b;
bool check(int x,int q){
    while(x % q == 0)x /= q;
    return x == 1 || x % b == 1;
}
void solve(){
    bool flag = false;
    for(int i = 0; i <= 40 ; ++ i){
        ll temp = 1;
        for(int j = 0 ; j < i; ++ j){
            temp *= a;
        }
        if(temp > n)break;
        if((n - temp) % b == 0){
            flag = true;
        }
    }
    if(flag){
        puts("YES");
    }
    else{
        puts("NO");
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> a >> b;
        solve();
    }
    return 0;
}