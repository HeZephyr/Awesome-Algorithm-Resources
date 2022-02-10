/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-03 19:03
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

ll l,r;
set<ll> v;
void init(){
    for(int i = 0; i <= 9; ++ i){
        for(int j = 0; j + i <= 9; ++ j){
            if(i == 0 && j == 0)continue;
            string s = "";
            for(int k = 0; k < i; ++ k){
                s += "4";
            }
            for(int k = 0; k < j; ++ k){
                s += "7";
            }
            do{
                v.insert(atoi(s.c_str()));
            }while(next_permutation(s.begin(),s.end()));
        }
    }
    v.insert(4444444444);
}
void solve(){
    ll ans = 0;
    for(ll x : v){
        if(x >= l){
            if(x > r){
                ans += 1LL * (r - l + 1) * x;
            }
            else{
                ans += 1LL * (x - l + 1) * x;
            }
            l = x + 1;
        }
        if(l > r)break;
    }
    cout << ans << endl;
}
int main(){
    init();
    while( cin >> l >> r ){
        solve();
    }
    return 0;
}