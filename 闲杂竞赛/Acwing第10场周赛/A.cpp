/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-31 19:00
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
ll a,b;
void solve(){
    if(a <= b){
        cout << b - a << endl;
    }
    else{
        cout << (a + b - 1) / b * b - a << endl;
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> a >> b;
        solve();
    }
    return 0;
}