/**
  *@filename:A_ABC_String
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-14 08:25
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
string s;
void solve(){
    n = s.size();
    char pre = s[0],ed = s[n - 1];
    if(pre == ed){
        puts("NO");
        return;
    }
    map<char,int> p;
    int cnt = 0;
    for(auto &x : s){
        p[x] ++;
    }
    bool flag = true;
    if(p[pre] * 2 == n){
        for(auto &x : s){
            if(x == pre){
                p['('] ++;
            }
            else{
                if(p['(']){
                    p['('] --;
                }
                else{
                    flag = false;
                    break;
                }
            }
        }
        if(p['(']){
            flag = false;
        }
    }
    else if(p[ed] * 2 == n){
        for(auto &x : s){
            if(x == ed){
                if(p['(']){
                    p['('] --;
                }
                else{
                    flag = false;
                    break;
                }
            }
            else{
                p['('] ++;
            }
        }
        if(p['(']){
            flag = false;
        }
    }
    else{
        flag = false;
    }
    if(flag){
        puts("YES");
    }
    else{
        puts("NO");
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