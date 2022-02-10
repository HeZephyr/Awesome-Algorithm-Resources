/**
  *@filename:B_Mocha_and_Red_and_Blue
  *@author: pursuit
  *@created: 2021-08-15 22:49
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n;
string s;
void solve(){
    char pre = 'a';
    bool flag = false;
    while(true){
        bool flag1 = false,flag2 = false;
        for(int i = 0; i < n; ++ i){
            if(s[i] == 'B' || s[i] == 'R'){
                flag1 = true;
                if(i - 1 >= 0 && s[i - 1] == '?'){
                    if(s[i] == 'B')s[i - 1] = 'R';
                    else s[i - 1] = 'B';
                    flag2 = true;
                }
                if(i + 1 < n && s[i + 1] == '?'){
                    if(s[i] == 'R')s[i + 1] = 'B';
                    else s[i + 1] = 'R';
                    flag2 = true;
                }
                //cout << s[i] << " ";
            }
        }
        if(!flag1){
            s[0] = 'B';
        }
        if(flag1 && !flag2){
            break;
        }
    }
    cout << s << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n >> s;
        solve();
    }
    return 0;
}