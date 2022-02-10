/**
  *@filename:BBB
  *@author: pursuit
  *@created: 2021-10-13 22:40
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t;
string s;
void solve(){
    int res = INF;
    string temp = "00";
    int cnt = 0, idx = 0;
    bool flag = false;
    for(int i = s.size() - 1; i >= 0; -- i){
        if(s[i] == temp[idx]){
            ++ idx;
            if(i == 0)flag = true;
            if(idx == temp.size())break;
        }
        else{
            ++ cnt;
        }
    }
    if(!flag && idx == temp.size()){
        res = min(res, cnt);
    }
    temp = "52";
    cnt = idx = 0;
    for(int i = s.size() - 1; i >= 0; -- i){
        if(s[i] == temp[idx]){
            ++ idx;
            if(idx == temp.size())break;
        }
        else{
            ++ cnt;
        }
    }
    if(idx == temp.size()){
        res = min(res, cnt);
    }
    temp = "05";
    cnt = idx = 0;
    for(int i = s.size() - 1; i >= 0; -- i){
        if(s[i] == temp[idx]){
            ++ idx;
            if(idx == temp.size())break;
        }
        else{
            ++ cnt;
        }
    }
    if(idx == temp.size()){
        res = min(res, cnt);
    }
    temp = "57";
    cnt = idx = 0;
    for(int i = s.size() - 1; i >= 0; -- i){
        if(s[i] == temp[idx]){
            ++ idx;
            if(idx == temp.size())break;
        }
        else{
            ++ cnt;
        }
    }
    if(idx == temp.size()){
        res = min(res, cnt);
    }
    cout << res << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> s;
        solve();
    }
    return 0;
}