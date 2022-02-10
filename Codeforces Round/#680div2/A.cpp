/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-08 08:07
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5;
const int P = 1e9+7;

int t,n,x,a[N],b[N];
void solve(){
    sort(a + 1,a + 1 + n);
    sort(b + 1,b + 1 + n,greater<int>() );
    for(int i = 1; i <= n; ++ i){
        if(a[i] + b[i] > x){
            puts("NO");
            return;
        }
    }
    puts("YES");
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> x;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
        }
        for(int i = 1; i <= n; ++ i){
            cin >> b[i];
        }
        solve();
    }
    return 0;
}