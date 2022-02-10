/**
  *@filename:A_Yet_Another_String_Game
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-01 16:40
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
string s;
void solve(){
    //Alice want to be min,Bob want to be max, Alice first;
    bool flag = true;
    for(auto &x : s){
        if(flag){
            //让其最小。
            if(x == 'a'){
                x = 'b';
            }
            else{
                x = 'a';
            }
        }
        else{
            //让其最大。
            if(x == 'z'){
                x = 'y';
            }
            else{
                x = 'z';
            }
        }
        flag = !flag;
    }
    cout << s << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> s;
        solve();
    }
    return 0;
}