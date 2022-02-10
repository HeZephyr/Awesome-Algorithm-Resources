/**
  *@filename:D
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-28 19:08
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 500 + 5;
const int P = 1e9+7;

int n;
ll a[N * N];
bool cmp(ll a,ll b){
    return a > b;
}
void solve(){
}
int main(){
    cin >> n;
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < n; ++ j){
            cin >> a[i * n + j];
        }
    }
    sort(a,a + n * n,cmp);
    ll cnt = 0;
    for(int i = 0; i < n; ++ i){
        cnt += a[i];
    }
    cout << cnt <<" ";
    for(int i = n; i < n - 1; ++ i){
        cnt += a[i] - a[i - 1];
        cout << cnt << " ";
    }
    cout << endl;
    solve();
    return 0;
}