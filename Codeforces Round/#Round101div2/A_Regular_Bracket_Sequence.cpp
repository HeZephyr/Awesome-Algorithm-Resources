/**
  *@filename:A_Regular_Bracket_Sequence
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-03 15:27
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
string s;
map<char,int> p;
void solve(){
    int n = s.size();
    if((n & 1) || s[0] == ')' || s[n - 1] == '('){
        puts("NO");
    }
    else{
        puts("YES");
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