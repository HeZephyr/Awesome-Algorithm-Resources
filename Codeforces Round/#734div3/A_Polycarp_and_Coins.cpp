/**
  *@filename:A_Polycarp_and_Coins
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-23 22:35
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
void solve(){
    if(n % 3 == 0){
        cout << n / 3 << " " << n / 3 << endl;
    }
    else if(n % 3 == 1){
        cout << (n + 2) / 3 << " " << (n + 2) / 3 - 1 << endl;
    }
    else{
        cout << (n - 2) / 3 << " " << (n - 2) / 3 + 1 << endl;
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