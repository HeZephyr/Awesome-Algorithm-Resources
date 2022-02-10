/**
  *@filename:C_Strange_Birthday_Party
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-02 20:36
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 300000 + 5;
const int P = 1e9+7;

int t,n,m,k[N],c[N];
void solve(){
    sort(k + 1 ,k + 1 + n,greater<int>());
    int d = 1;
    ll sum = 0;
    for(int i = 1; i <= n; ++ i){
        if(k[i] >= d)sum += c[d ++ ];
        else sum += c[k[i]];
    }
    cout << sum << endl;
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &k[i]);
        }
        for(int i = 1; i <= m; ++ i){
            scanf("%d", &c[i]);
        }
        solve();
    }
    return 0;
}