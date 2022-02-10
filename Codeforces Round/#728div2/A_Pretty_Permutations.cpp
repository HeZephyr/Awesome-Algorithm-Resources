/**
  *@filename:A_Pretty_Permutations
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-25 23:36
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
void solve(){
    if(n & 1){
        for(int i = 1; i < n - 2; i += 2){
            cout << i + 1 << " " << i << " ";
        }
        cout << n  <<  " " << n - 2 << " " << n - 1 << endl;
    }
    else{
        for(int i = 1; i < n; i += 2){
            cout << i + 1 << " " << i << " ";
        }
        cout << endl;
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        solve();
    }
    return 0;
}