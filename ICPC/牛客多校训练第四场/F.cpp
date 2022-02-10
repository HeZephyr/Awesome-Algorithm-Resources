/**
  *@filename:F
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-26 12:20
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 110 + 5;
const int P = 1e9+7;

int n,m,u,v;
void solve(){
    
    if((n + m) & 1){
        cout << "Alice" << endl;
    }
    else{
        cout << "Bob" << endl;
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++ i){
        cin >> u >> v;
    }
    solve();
    return 0;
}