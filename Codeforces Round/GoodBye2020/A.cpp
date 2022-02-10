/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-26 14:16
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,x[N];
map<int,int> p;
void solve(){
    p.clear();
    int cnt = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = i + 1; j <= n; ++ j){
            if(x[j] - x[i] != 0 && p[x[j] - x[i]] == 0){
                cnt ++;
                p[x[j] - x[i]] ++;
            }
        }
    }
    cout << cnt << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        for(int i = 1; i <= n; ++ i){
            cin >> x[i];
        }
        solve();
    }
    return 0;
}