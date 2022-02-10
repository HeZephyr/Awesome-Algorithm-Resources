/**
  *@filename:A_Casimir_s_String_Solitaire
  *@author: pursuit
  *@created: 2021-09-28 22:35
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
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> s;
        int cnt[3];
        cnt[0] = cnt[1] = cnt[2] = 0;
        for(int i = 0; i < s.size(); ++ i){
            cnt[s[i] - 'A'] ++;
        }
        if(cnt[1] == cnt[0] + cnt[2])puts("YES");
        else puts("NO");
    }
    solve();
    return 0;
}