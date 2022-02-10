/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-18 18:59
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

string s;
void solve(){
    for(int i = 0; i < s.size(); ++ i){
        if(s[i] == '<'){
            cout << "&lt;";
        }
        else if(s[i] == '>'){
            cout << "&gt;";
        }
        else{
            cout << s[i];
        }
    }
    cout << endl;
}
int main(){
    getline(cin,s);
    solve();
    return 0;
}