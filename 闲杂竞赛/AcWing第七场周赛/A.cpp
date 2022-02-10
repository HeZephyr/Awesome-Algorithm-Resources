/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-10 19:00
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,h,m;
void solve(){
    int h1 = 24 - h;
    cout << h1 * 60 - m << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> h >> m;
        solve();
    }
    return 0;
}