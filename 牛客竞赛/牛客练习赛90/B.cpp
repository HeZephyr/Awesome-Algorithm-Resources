/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-10-29 19:16
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
    ll sum = 0;
    for(int i = 0; i < s.size(); ++ i){
        if(s[i] == '1'){
            sum += (i + 1);
        }
    }
    if(sum & 1){
        puts("T");
    }
    else{
        puts("X");
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