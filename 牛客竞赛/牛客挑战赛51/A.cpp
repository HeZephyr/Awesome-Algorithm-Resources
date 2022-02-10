/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-19 19:00
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

ll a,b,c,d;
ll gcd(ll n,ll m){
    if(!m)return n;
    return n % m ? gcd(m,n % m) : m;
}
void solve(){
    ll temp = a * c / gcd(a,c);
    if(b % temp || d % temp){
        cout << - 1 << endl;
    }
    else{
        bool flag = false;
        ll x = temp,k = 1;
        while(x < min(b,d)){
            x = temp * k;
            if(x > a && x < b && x > c && x < d && b % x == 0 && d % x == 0){
                flag = true;
                break;
            }
            k ++;
        }
        if(flag){
            cout << x << endl;
        }
        else{
            cout << - 1 << endl;
        }
    }
}
int main(){
    cin >> a >> b >> c >> d;
    solve();
    return 0;
}