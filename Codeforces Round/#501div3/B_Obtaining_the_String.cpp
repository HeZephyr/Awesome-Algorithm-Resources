/**
  *@filename:B_Obtaining_the_String
  *@author: pursuit
  *@created: 2021-10-26 19:05
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
char s[N], t[N];
int cnt[2][26];
void solve(){
    for(int i = 0; i < n; ++ i){
        cnt[0][s[i] - 'a'] ++;
        cnt[1][t[i] - 'a'] ++;
    }
    for(int j = 0; j < 26; ++ j){
        if(cnt[0][j] != cnt[1][j]){
            puts("-1");
            return;
        }
    }
    vector<int> res;
    for(int i = 0; i < n; ++ i){
        if(s[i] != t[i]){
            int idx;        
            for(int j = i + 1; j < n; ++ j){
                if(s[j] == t[i]){
                    idx = j;
                    break;
                }
            }
            while(idx > i){
                res.push_back(idx - 1);
                swap(s[idx - 1], s[idx]);
                -- idx;
            }
        }
    }
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); ++ i){
        cout << res[i] + 1 << " ";
    }
    cout << endl;
    //cout << s << endl;
}
int main(){	
    cin >> n;
    cin >> s >> t;
    solve();
    return 0;
}