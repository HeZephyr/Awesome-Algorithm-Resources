/**
  *@filename:Yiwen_with_Sqc
  *@author: pursuit
  *@created: 2021-08-10 12:29
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

vector<int> pos[26];
int t,n;
char s[N];
void solve(){
    n = strlen(s + 1);
    for(int i = 1; i <= n; ++ i){
        pos[s[i] - 'a'].push_back(i);
    }
    ll ans = 0;
    
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> s + 1;	
        solve();
    }
    return 0;
}