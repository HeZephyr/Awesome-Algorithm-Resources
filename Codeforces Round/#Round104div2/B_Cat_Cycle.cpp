/**
  *@filename:B_Cat_Cycle
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-25 16:55
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,k;
void solve(){
    k --;
    if(n & 1){
        cout << 1 + (k / n + k) % n << endl;
    }
    else{
        cout << 1 + k % n << endl;
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> k;
        solve();
    }
    return 0;
}