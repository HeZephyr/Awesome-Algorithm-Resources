/**
  *@filename:G
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-22 21:47
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 5;
const int P = 1e9+7;

int n,m,a,c;
ll x[N];
int cal(int l, int r, ll num){
    if(l > r)return 0;
    int mid = l + r >> 1;
    if(x[mid] == num)return 1;
    if(num < x[mid]){
        return cal(l, mid - 1,num);
    }
    return cal(mid + 1, r, num);
}
void solve(){
    int ans = 0;
    for(int i = 1; i <= n; ++ i){
        ans += cal(1, n, x[i]);
    }
    cout << ans << endl;
}
int main(){
    cin >> n >> m >> a >> c >> x[0];
    for(int i = 1; i <= n; ++ i){
        x[i] = (x[i - 1] * a + c) % m;
    }
    solve();
    return 0;
}