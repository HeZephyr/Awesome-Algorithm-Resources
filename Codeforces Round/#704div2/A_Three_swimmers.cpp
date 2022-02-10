/**
  *@filename:A_Three_swimmers
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-19 19:36
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
ll a,b,c,p;
void solve(){
    ll temp;
    if(p % a && p % b && p % c){
        temp = min(a - (p - p / a * a),min(b - (p - p / b * b),c - (p - p / c * c)));
    }
    else{
        temp = 0;
    }
    cout << temp << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> p >> a >> b >> c;
        solve();
    }
    return 0;
}