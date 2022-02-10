/**
  *@filename:A_Replacing_Elements
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-02 11:30
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5;
const int P = 1e9+7;

int t,n,d,a[N];
void solve(){
    sort(a + 1, a + 1 + n);
    if(a[1] + a[2] <= d || a[n] <= d){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> d;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
        }
        solve();
    }
    return 0;
}