/**
  *@filename:A+B_Problem
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-23 19:54
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,a,b;
void solve(){
    int temp = a + b;
    if(temp >= -1024 && temp <= 1023){
        cout << temp << endl;
    }
    else if(temp > 1023){
        cout << temp - 2048 << endl;
    }
    else{
        cout << 2048 + temp << endl;
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