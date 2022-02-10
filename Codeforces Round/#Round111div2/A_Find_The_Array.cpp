/**
  *@filename:A_Find_The_Array
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-25 20:34
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
void solve(){
    int cnt = 0,temp = 1;
    while(n >= temp){
        cnt ++;
        n -= temp;
        temp += 2;
    }
    cout << cnt  + (n > 0) << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        solve();
    }
    return 0;
}