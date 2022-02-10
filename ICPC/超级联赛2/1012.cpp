/**
  *@filename:1012
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-22 12:01
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
string s;
void solve(){
    string str = "114514";
    int l = 0;
    bool flag = false;
    for(int i = 0; i < s.size(); ++ i){
        if(s[i] == str[l]){
            l ++;
            if(l == str.size()){
                flag = true;
                break;
            }
        }
    }
    if(flag){
        cout << "AAAAAA" << endl;
    }
    else{
        cout << "Abuchulaile" << endl;
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