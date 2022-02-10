/**
  *@filename:H
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-31 12:04
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000 + 5;
const int P = 1e9+7;

int n,m;
void solve(){
    for(int i = 1; i <= n; ++ i){
        int op;
        if(i & 1)op = 1;
        else op = 0;
        for(int j = 1; j <= m; ++ j){
            cout << char(op + '0');
            if(j % 2 == 0){
                op ^= 1;
            }
        }
        cout << endl;
    }
}
int main(){
    cin >> n >> m;
    solve();
    return 0;
}