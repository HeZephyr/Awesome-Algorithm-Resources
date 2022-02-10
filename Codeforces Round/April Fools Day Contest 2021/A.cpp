/**
  *@filename:A
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-07 15:26
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

string s;
void solve(){
}
int main(){
    while(getline(cin,s)){
        if(s.find("?")!=s.npos){
            puts("NO");
        }
        else{
            puts("YES");
        }
        cout.flush();
        solve();
    }
    return 0;
}