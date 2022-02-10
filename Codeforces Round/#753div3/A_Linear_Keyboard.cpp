/**
  *@filename:A_Linear_Keyboard
  *@author: pursuit
  *@created: 2021-11-02 22:35
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
string s1, s2;
int cnt[26];
void solve(){
    int res = 0;
    for(int i = 0; i < s2.size() - 1; ++ i){
        res += abs(cnt[s2[i + 1] - 'a'] - cnt[s2[i] - 'a']);
    }
    cout << res << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> s1 >> s2;
        for(int i = 0; i < 26; ++ i){
            cnt[s1[i] - 'a'] = i;
        }
        solve();
    }
    return 0;
}