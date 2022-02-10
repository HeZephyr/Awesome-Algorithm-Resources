/**
  *@filename:K_Segment_Tree_with_Pruning
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-27 12:27
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
ll k,n;
unordered_map<ll,ll> p;
ll build(ll n){
    if(p.find(n) != p.end())return p[n];
    if(n <= k)return p[n] = 1;
    return p[n] = build(n / 2) + build(n - n / 2) + 1;
}
void solve(){
    p.clear();
    cout << build(n) << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> k;
        solve();
    }
    return 0;
}