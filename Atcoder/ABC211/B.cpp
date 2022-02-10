/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-24 20:03
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

string s;
map<string,int> p;
void solve(){
}
int main(){
    for(int i = 0; i < 4; ++ i){
        cin >> s;
        p[s] ++;
    }
    if(p["H"] && p["2B"] && p["3B"] && p["HR"]){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    solve();
    return 0;
}