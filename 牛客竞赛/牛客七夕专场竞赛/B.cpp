/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-14 19:26
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,k;
string s;
bool cnt[26];
void solve(){
    string temp;
    dfs(0,temp);
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n >> k;
        cin >> s;
        memset(cnt,0,sizeof(cnt));
        for(int i = 0; i < s.size(); ++ i){
            cnt[s[i] - 'a'] = true;
        }
        solve();
    }
    return 0;
}