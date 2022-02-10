/**
  *@filename:Calculus
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-29 12:07
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
string s;
void solve(){
    int cnt0 = 0,cnt = 0;
    for(int i = 0; i < s.size(); ++ i){
        if(isdigit(s[i])){
            cnt++;
        }
        if(s[i] == '0'){
            cnt0 ++;
        }
    }
    if(cnt == cnt0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> s;
        solve();
    }
    return 0;
}