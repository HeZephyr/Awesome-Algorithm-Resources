/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-09-11 18:56
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, x, y;
char s[N];
void solve(){
    int n = strlen(s + 1);
    for(int i = 1; i <= n; ++ i){
        if(s[i] >= 'a' && s[i] <= 'z')++ x;
        else ++ y;
    }
    if(x >= y){
        for(int i = 1; i <= n; ++ i){
            if(s[i] >= 'A' && s[i] <= 'Z')s[i] += 32;
        }
    }
    else{
        for(int i = 1; i <= n; ++ i){
            if(s[i] >= 'a' && s[i] <= 'z')s[i] -= 32;
        }
    }
    cout << (s + 1) << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        x = y = 0;
        cin >> s + 1;
        solve();
    }
    return 0;
}