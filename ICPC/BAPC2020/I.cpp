/**
  *@filename:I
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-30 14:46
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int c,e,m;
void solve(){
    if(c != 4 || e % 4 != 0){
        cout << "impossible" << endl;
        return;
    }
    //(a + b) * 2 = e
    //a * b = m;
    int a1,a2,b1,b2;
    //2a^2 - ea + 2m = 0;
    //利用求根公式。
    a1 = (e + sqrt(1.0 * e * e - 16.0 * m)) / 4;
    a2 = (e - sqrt(1.0 * e * e - 16.0 * m)) / 4;
    b1 = e / 2 - a1;
    b2 = e / 2 - a2;
    if(a1 * b1 == m){
        cout << a1 + 2 << " " << b1 + 2 << endl;
    }
    else if(a2 * b2 == m){
        cout << a2 + 2 << " " << b2 + 2 << endl;
    }
    else{
        cout << "impossible" << endl;
    }
}
int main(){
    cin >> c >> e >> m;
    solve();
    return 0;
}