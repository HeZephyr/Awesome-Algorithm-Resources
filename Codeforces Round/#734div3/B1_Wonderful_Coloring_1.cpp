/**
  *@filename:B1_Wonderful_Coloring_1
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-23 22:50
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
string s;
int cnt[27];
void solve(){
    memset(cnt,0,sizeof(cnt));
    for(auto &x : s){
        cnt[x - 'a'] ++;
    }
    int temp = 0,ans = 0;
    for(int i = 0; i < 27; ++ i){
        if(cnt[i] > 1)ans++;
        else if(cnt[i] == 1)temp ++;
    }
    cout << ans + temp / 2 << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> s;
        solve();
    }
    return 0;
}