/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-10 20:00
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int a,b;
void solve(){
}
int main(){
    cin >> a >> b;
    if(a > b){
        cout << 0 << endl;
    }
    else{
        cout << b - a + 1 << endl;
    }
    solve();
    return 0;
}