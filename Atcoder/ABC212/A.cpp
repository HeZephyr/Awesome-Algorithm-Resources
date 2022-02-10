/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-08-01 19:44
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int a,b;
void solve(){
    if(a > 0 && b == 0){
        cout << "Gold" << endl;
    }
    else if(a == 0 && b > 0){
        cout << "Silver" << endl;
    }
    if(a > 0 && b > 0){
        cout << "Alloy" << endl;
    }
}
int main(){
    cin >> a >> b;
    solve();
    return 0;
}