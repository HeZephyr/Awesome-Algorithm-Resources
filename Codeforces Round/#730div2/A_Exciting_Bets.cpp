/**
  *@filename:A_Exciting_Bets
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-07 22:36
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
ll a,b;
ll gcd(ll n, ll m){
    if(!m)return n;
    return n % m ? gcd(m, n % m) : m;
}
void solve(){
    if(a == b){
        cout << "0 0" << endl;
    }
    else if(abs(a - b) == 1){
        cout << "1 0" << endl;
    }
    else{
        ll maxx = abs(a - b);
        if(a < b)swap(a,b);
        if(maxx == b){
            cout << maxx << " 0" << endl;
        }
        else{
            cout << maxx << " " << min(a % maxx,abs(maxx - a % maxx)) << endl;
        }
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