/**
  *@filename:B_Alphabetical_Strings
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-10 22:44
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
string s;
void solve(){
    int l = -1, r = -1;
    for(int i = 0; i < s.size(); ++ i){
        if(s[i] == 'a'){
            l = r = i;
        }
    }
    if(l == -1){
        cout << "NO" << endl;
        return;
    }
    char temp = 'b';
    l -= 1,r += 1;
    bool flag = false;
    while((l >= 0 && s[l] == temp) || (r < s.size() &&s[r] == temp)){
        if(l >= 0 && s[l] == temp){
            l -= 1;
            temp = temp + 1;
        }
        if(r < s.size() && s[r] == temp){
            r += 1;
            temp = temp + 1;
        }
    }
    if(temp - 'a' != s.size()){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
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