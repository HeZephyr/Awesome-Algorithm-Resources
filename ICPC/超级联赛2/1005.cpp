/**
  *@filename:1005
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-22 12:09
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
string s;
ll quick_pow(ll n, ll q){
    ll ans = 1;
    while(q){
        if(q & 1)ans = ans * n % P;
        n = n * n % P;
        q >>= 1;
    }
    return ans;
}
void solve(){
    //多少种操作方式能够得到这最大分数。
    ll cnt = 0;
    char pre = s[0];
    for(int i = 0; i < n; ++ i){
        if(pre == s[i])cnt++;
        else break;
    }
    cout << quick_pow(2,cnt - 1) << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> s;
        solve();
    }
    return 0;
}