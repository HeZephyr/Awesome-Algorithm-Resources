/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-10 20:02
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,x;
void solve(){
}
int main(){
    cin >> n >> x;
    int ans = 0,temp;
    for(int i = 1; i <= n; ++ i){
        cin >> temp;
        if(i % 2 == 0){
            temp -= 1;
        }
        ans += temp;
    }
    if(x >= ans){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    solve();
    return 0;
}