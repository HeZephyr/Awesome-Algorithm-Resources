/**
  *@filename:A_PizzaForces
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-30 22:35
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
ll n;
void solve(){
    if(n % 6 == 0 || n % 8 == 0 || n % 10 == 0){
        cout << n / 2 * 5 << endl;
    }
    else if(n > 6 * 8 * 10){
        if(n & 1)n ++;
        cout << n / 2 * 5 << endl;
    }
    else{
        ll minn = n * 100;
        for(int i = 0; i <= 100; ++ i){
            for(int j = 0; j <= 100; ++ j){
                for(int k = 0; k <= 100; ++ k){
                    if(i * 6 + j * 8 + k * 10 >= n){
                        minn = min(1LL * i * 15 + j * 20 + k * 25,minn); 
                    }
                }
            }
        }
        cout << minn << endl;
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