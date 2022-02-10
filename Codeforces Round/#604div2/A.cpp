/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-09 17:19
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
    char pre = '.';
    bool flag = false;
    int len = s.size();
    for(int i = 0; i < len; ++ i){
        if(s[i] == '?'){
            for(int j = 0; j < 3; ++ j){
                //枚举修改。
                s[i] = 'a' + j;
                if(i == 0 && s[i] != s[i + 1]){
                    break;
                }
                else if(i == len - 1 && s[i] != s[i - 1]){
                    break;
                }
                else if(s[i] != s[i - 1] && s[i] != s[i + 1]){
                    break;
                }
            }
        }
    }
    for(int i = 0; i < len - 1; ++ i){
        if(s[i] == s[i + 1]){
            flag = true;
        }
    }
    if(flag){
        cout << -1 << endl;
    }
    else{
        cout << s << endl;
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