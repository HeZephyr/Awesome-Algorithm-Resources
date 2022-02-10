/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-04 20:06
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int n;
ll k,a[N];
int pos[N];
map<int,int> p;
bool cmp(int i,int j){
    return a[i] < a[j];
}
void solve(){
    sort(pos + 1, pos + 1 + n,cmp);
    ll ans = k / n;
    k -= ans * n;
    for(int i = i; i <= k; ++ i){
        p[a[pos[i]]] ++;
    }
    for(int i = 1; i <= n; ++ i){
        cout << ans + p[a[i]] << endl;
    }
}
int main(){
    scanf("%d", &n);
    scanf("%lld", &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
        pos[i] = i;
    }
    solve();
    return 0;
}