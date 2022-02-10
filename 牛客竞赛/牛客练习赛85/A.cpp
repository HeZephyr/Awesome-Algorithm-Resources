/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-26 12:50
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

char a[8][8];
void solve(){
    for(int i = 1; i <= 5; ++ i){
        for(int j = 1; j <= 5; ++ j){
            if(a[i][j] == '1' && a[i - 1][j] == '1' && a[i + 1][j] == '1' && a[i][j + 1] == '1'){
                cout << 8 << endl;
                return;
            }
        }
    }
    for(int i = 1; i <= 5; ++ i){
        for(int j = 1; j <= 5; ++ j){
            if(a[i][j] == '1' && a[i - 1][j] == '1' && a[i + 1][j] == '1' && a[i][j - 1] == '1'){
                cout << 9 << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
}
int main(){
    for(int i = 1; i <= 5; ++ i){
        for(int j = 1; j <= 5; ++ j){
            cin >> a[i][j];
        }
    }
    solve();
    return 0;
}