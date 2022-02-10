/**
  *@filename:D_Co_growing_Sequence
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-10 23:11
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,n,x[N];
void solve(){
    cout << "0";
    for(int i = 2; i <= n; ++ i){
        cout << " " << x[i - 1] - (x[i] & x[i - 1]);
        x[i] ^= x[i - 1] - (x[i] & x[i - 1]);
    }
    cout << endl;
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &x[i]);
        }
        solve();
    }
    return 0;
}