/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-10 19:02
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

ll t,n,k;
bool check(ll x){
    return k <= x * (x + 1) / 2;
}
void solve(){
    //二分。
    ll l = 0, r = n - 1,mid;
    while(l < r){
        mid = l + r >> 1;
        if(check(mid)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    k -= l * (l - 1) / 2;
    //l 是 不符合的，我们需要固定一个不符合的。
    //cout << l << " " << k << endl;
    for(int i = n; i >= 1; -- i){
        if(i == l + 1 || i == k){
            cout << 'b';
        }
        else{
            cout << 'a';
        }
    }
    cout << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> k;
        solve();
    }
    return 0;
}