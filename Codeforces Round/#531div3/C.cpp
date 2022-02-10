/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-27 21:09
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,x,y;
int ans;
void solve(){
    //根据先手和后手决定。先手必定试想尽可能消灭当前能消灭的最大值。
    if(x > y){
        cout << n << endl;
    }
    else if(x <= y){
        cout << (ans + 1) / 2 << endl;
    }
}
int main(){
    cin >> n >> x >> y;
    int temp;
    for(int i = 1; i <= n; ++ i){
        cin >> temp;
        if(temp <= x){
            ans ++;
        }
    }
    solve();
    return 0;
}