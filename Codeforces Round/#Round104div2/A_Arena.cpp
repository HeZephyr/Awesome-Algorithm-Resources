/**
  *@filename:A_Arena
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-25 15:11
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5;
const int P = 1e9+7;

int t,n,a[N];
void solve(){
    sort(a + 1,a + 1 + n);
    int cnt = 0;
    int x = a[1];
    for(int i = 1; i <= n; ++ i){
        if(x != a[i])cnt ++;
    }
    cout << cnt << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        for(int i = 1;i <= n; ++ i){
            cin >> a[i];
        }
        solve();
    }
    return 0;
}