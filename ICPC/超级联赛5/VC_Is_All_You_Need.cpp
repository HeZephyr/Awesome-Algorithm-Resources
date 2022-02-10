/**
  *@filename:VC_Is_All_You_Need
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-08-03 12:47
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
ll n,k;
void solve(){
    if(n - k <= 1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
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