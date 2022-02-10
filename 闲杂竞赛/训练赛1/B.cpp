/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-08 19:01
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int k;
string s;
void solve(){
    int len = s.size();
    for(int i = 0; i < k; ++ i){
        if(len > 0){
            if(s[len - 1] != '0'){
                s[len - 1] -= 1;
            }
            else{
                len --;
            }
        }
    }
    for(int i = 0; i < len; ++ i){
        cout << s[i];
    }
    cout << endl;
}
int main(){
    cin >> s >> k;	
    solve();
    return 0;
}