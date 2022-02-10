/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-03 19:00
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000 + 5;
const int P = 1e9+7;

int n,a[N];
void solve(){
}
int main(){
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
        if(a[i] & 1){
            cnt ++;
        }
    }
    if(cnt & 1){
        cout << cnt << endl;
    }
    else{
        cout << n - cnt << endl;
    }
    solve();
    return 0;
}