/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-21 21:24
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n;
ll a[N];
unordered_set<ll> t;//set存放。
void solve(){
    ll ans = 0;
    int l = 1, r = 1;
    while(l <= r){
        while(r <= n && !t.count(a[r])){
            t.insert(a[r]);
            r ++;
        }
        ans += r - l;
        t.erase(a[l]);
        l ++;
    }
    cout << ans << endl;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}