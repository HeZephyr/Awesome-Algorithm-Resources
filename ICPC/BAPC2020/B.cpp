/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-31 00:35
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

ll n;
vector<ll> result;
ll cal(ll n){
    if(n >= 11 && n <= 99)return n / 11 * 11;
    string s = to_string(n);
    string half = s;
    reverse(half.begin(),half.end());
    if(s == half)return n;
    if(stoll(half) == 1){
        return n - 1;
    }
    half = s.substr(0, s.size() + 1 >> 1);
    half = to_string(stoll(half) - 1); //将左半端取出来减1.
    string ans = half;
    int st = half.size() - 1 - s.size() % 2;
    for(int i = st; i >= 0; -- i){
        ans += half[i];
    }
    return stoll(ans);
}
void solve(){
    while(n){
        ll m = cal(n);
        //cout << m << endl;
        result.push_back(m);
        n -= m;
    }
    cout << result.size() << endl;
    for(ll &x : result){
        cout << x << endl;
    }
}
int main(){
    cin >> n;
    solve();
    return 0;
}