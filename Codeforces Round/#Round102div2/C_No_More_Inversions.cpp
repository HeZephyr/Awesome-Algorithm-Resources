/**
  *@filename:C_No_More_Inversions
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-02 11:43
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,k;
void solve(){
    if(n > k & k > 1){
        for(int i = 1; i <= k - (n - k + 1); ++ i){
            cout << i << " ";//回文串是固定的，只能填k - (n - k - 1)个数。
        }
        for(int i = k; i >= k - (n - k); -- i){
            cout << i << " ";
        }
    }
    else{
        for(int i = 1; i <= k; ++ i){
            cout << i << " ";
        }
    }
    cout << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> k;
        solve();
    }
    return 0;
}