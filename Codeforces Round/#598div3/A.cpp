/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-28 12:50
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
ll a,b,n,s;
void solve(){
    if(s % n <= b && n * a + b >= s){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> a >> b >> n >> s;
        solve();
    } 
    return 0;
}