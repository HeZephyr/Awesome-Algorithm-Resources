/**
  *@filename:B_Red_and_Blue
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-03 15:54
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5;
const int P = 1e9+7;

int t,n,m,r[N],b[N];
void solve(){
    int maxx = 0;
    for(int i = 0; i <= n; ++ i){
        for(int j = 0; j <= m; ++ j){
            maxx = max(maxx,r[i] + b[j]);
        }
    }
    cout << maxx << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n ;
        for(int i = 1; i <= n; ++ i){
            cin >> r[i];
            r[i] += r[i - 1];
        }
        cin >> m;
        for(int i = 1; i <= m; ++ i){
            cin >> b[i];
            b[i] += b[i - 1];
        }
        solve();
    }
    return 0;
}