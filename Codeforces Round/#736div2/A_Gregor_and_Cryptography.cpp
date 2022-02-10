/**
  *@filename:A_Gregor_and_Cryptography
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-08-01 22:35
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,p;
void solve(){
    /* if(p & 1){
        cout << 2 << " " << p - 1 << endl;
    }
    else{
        cout << 2 << " " << p << endl;
    } */
    if((p -1) % 2 == 0 && (p - 1) / 2 != 2){
        cout << 2 << " " << (p - 1) / 2 << endl;
    }
    else{
        cout << 2 << " " << 4 << endl;
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> p;
        solve();
    }
    return 0;
}