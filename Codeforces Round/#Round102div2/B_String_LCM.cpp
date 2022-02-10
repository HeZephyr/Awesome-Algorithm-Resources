/**
  *@filename:B_String_LCM
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-02 11:34
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
string s1,s2;
void solve(){
    string temp1 = s1,temp2 = s2;
    while(s1.size() != s2.size()){
        if(s1.size() < s2.size()){
            s1 += temp1;
        }
        else{
            s2 += temp2;
        }
    }
    if(s1 != s2){
        cout << -1 << endl;
    }
    else{
        cout << s1 << endl;
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> s1 >> s2;
        solve();
    }
    return 0;
}