/**
  *@filename:A_Arithmetic_Array
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-18 22:36
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5;
const int P = 1e9+7;

int t,n,a[N];
int sum;
void solve(){
    if(sum < n){
        cout << 1 << endl;
    }
    else{
        cout << sum - n << endl;
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        sum = 0;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
            sum += a[i];
        }
        solve();
    }
    return 0;
}