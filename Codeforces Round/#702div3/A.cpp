/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-07 08:48
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 50 + 5;
const int P = 1e9+7;

int t,n,a[N];
void solve(){
    int cnt = 0;
    for(int i = 2; i <= n; ++ i){
        int temp1 = max(a[i],a[i - 1]) ,temp2 = (min(a[i],a[i - 1]) * 2);
        while(temp1 > temp2){
            cnt ++;
            temp1 = (temp1 + 1) / 2;
        }
    }
    cout << cnt << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
        }
        solve();
    }
    return 0;
}