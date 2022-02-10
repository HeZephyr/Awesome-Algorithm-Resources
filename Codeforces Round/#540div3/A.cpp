/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-27 10:21
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
ll n,a,b;
void solve(){
    if(a * 2 <= b){
        cout << n * a << endl;
    }
    else{
        cout << n / 2 * b + ((n % 2) ? a : 0) << endl;
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> a >> b;
        solve(); 
    }
    return 0;
}