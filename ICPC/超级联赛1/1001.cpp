/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-20 12:14
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
ll n;
void solve(){
    if(n <= 2){
        cout << 0 << endl;
    }
    else{
        n -= 2;
        ll cnt = 1,temp = 2;
        while(n > temp){
            n -= temp;
            cnt = cnt * 2 + 1;
            temp *= 2;
        }
        cout << cnt << endl;
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