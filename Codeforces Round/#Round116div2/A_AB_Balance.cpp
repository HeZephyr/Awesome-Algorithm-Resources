/**
  *@filename:A_AB_Balance
  *@author: pursuit
  *@created: 2021-10-29 22:35
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
    int n = s.size();
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n - 1; ++ i){
        if(s[i] == 'a' && s[i + 1] == 'b')++ cnt1;
        else if(s[i] == 'b' && s[i + 1] == 'a')++ cnt2;
    }
    if(cnt1 == cnt2);
    else if(cnt1 > cnt2){
        if(s[0] == 'a' && s[1] == 'b'){
            s[0] = 'b';
        }
        else if(s[0] == 'a' && s[1] == 'a'){
            s[0] = 'b';
        }
    }
    else{
        if(s[0] == 'b' && s[1] == 'a'){
            s[0] = 'a';
        }
        else if(s[0] == 'b' && s[1] == 'b'){
            s[0] = 'a';
        }
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