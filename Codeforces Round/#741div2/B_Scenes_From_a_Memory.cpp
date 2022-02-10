/**
  *@filename:B_Scenes_From_a_Memory
  *@author: pursuit
  *@created: 2021-08-26 22:42
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,k;
string s;
void solve(){
    map<char,int> p;
    for(int i = 0; i < s.size(); ++ i){
        p[s[i]] ++;
        if(s[i] == '1'){
            cout << 1 << '\n' << 1 << endl;
            return;
        }
        else if(s[i] == '4'){
            cout << 1 << '\n' << 4 << endl;
            return;
        }
        else if(s[i] == '6'){
            cout << 1 << '\n' << 6 << endl;
            return;
        }
        else if(s[i] == '8'){
            cout << 1 << '\n' << 8 << endl;
            return;
        }
        else if(s[i] == '9'){
            cout << 1 << '\n' << 9 << endl;
            return;
        }
    }
    for(char i = '1'; i <= '9'; ++ i){
        if(p[i] > 1){
            cout << 2 << '\n' << i << i << endl;
            return;
        }
    }
    p.clear();
    //只有2357，且最多不会超过4个。
    for(int i = 0; i < s.size(); ++ i){
        if(s[i] == '2' && i != 0){
            cout << 2 << '\n' << s[i - 1] << 2 << endl;
            return;
        }
        else if(s[i] == '7' && p['2']){
            cout << 2 << '\n' << 2 << 7 << endl;
            return;
        }
        else if(s[i] == '5' && i != 0){
            cout << 2 << '\n' << s[i - 1] << 5 << endl;
            return;
        }
        else if(s[i] == '7' && p['5']){
            cout << 2 << '\n' << 57 << endl;
            return;
        }
        else
        p[s[i]] ++;
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> k >> s;
        solve();
    }
    return 0;
}