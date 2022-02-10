/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-07 08:49
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
ll x;
bool pow(ll x){
    ll l = 1,r = sqrt(x);
    while(l < r){
        ll mid = (l + r) >> 1;
        ll temp = mid * mid * mid;
        if(temp > x){
            r = mid - 1;
        }
        else if(temp == x){
            return true;
        }
        else{
            l = mid + 1;
        }
    }
    if(l * l * l == x || r * r * r == x)return true;
    return false;
}
void solve(){
    for(ll i = 1;; ++ i){
        if(i * i * i >= x)break;
        ll j = x - i * i * i;
        if(pow(j)){
            puts("YES");
            return;
        }
    }
    puts("NO");
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> x;
        solve();
    }
    return 0;
}