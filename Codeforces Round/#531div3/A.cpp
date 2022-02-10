/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-27 20:49
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n;
void solve(){
    if(n % 4 == 0 || n % 4 == 3){
        cout << "0" << endl;
    }
    else{
        cout << "1" << endl; 
    }
}
int main(){
    cin >> n;
    solve();
    return 0;
}