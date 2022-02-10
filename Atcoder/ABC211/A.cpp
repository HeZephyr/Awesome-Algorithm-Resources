/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-24 19:59
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
    if((a - b) % 3){
        printf("%.7lf\n",(a - b) * 1.0 / 3 + b);
    }
    else{
        cout << (a - b) / 3 + b << endl;
    }
    solve();
    return 0;
}