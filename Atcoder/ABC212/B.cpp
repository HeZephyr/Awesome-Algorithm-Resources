/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-08-01 19:48
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

char x[5];
void solve(){
    bool flag1 = false,flag2 = false;
    for(int i = 0; i < 3; ++ i){
        if(x[i] != x[i + 1]){
            flag1 = true;
        }
        if((x[i] + 1) % 10 != (x[i + 1] % 10)){
            flag2 = true;
        }
    }
    if(!flag1 || !flag2){
        cout << "Weak" << endl;
    }
    else{
        cout << "Strong" << endl;
    }
}
int main(){
    cin >> x;
    solve();
    return 0;
}