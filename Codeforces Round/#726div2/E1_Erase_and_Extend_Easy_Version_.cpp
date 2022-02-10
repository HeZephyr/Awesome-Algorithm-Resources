/**
  *@filename:E1_Erase_and_Extend_Easy_Version_
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-18 23:12
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,k;
string s;
string get(string s){
    while(s.size() < k){
        s += s;
    }
    return s.substr(0,k);
}
void solve(){
    string minn = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    while(minn.size() < k){
        minn += minn;
    }
    for(int i = 1; i <= n; ++ i){
        minn = min(minn,get(s.substr(0,i)));
    }
    cout << minn << endl;
}
int main(){
    cin >> n >> k;
    cin >> s;
    solve();
    return 0;
}