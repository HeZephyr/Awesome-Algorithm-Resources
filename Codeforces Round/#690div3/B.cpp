/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-09 14:13
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
string s;
void solve(){
    if((s.substr(0,1) == "2" && s.substr(n - 3,3) == "020") || (s.substr(0,4) == "2020" ) || 
    (s.substr(n - 4,4) == "2020") || (s.substr(0,3) == "202" && s.substr(n - 1,1) == "0") || 
    (s.substr(0,2) == "20" && s.substr(n - 2,2) == "20")){
        puts("YES");
    }
    else{
        puts("NO");
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> s;
        solve();
    }
    return 0;
}