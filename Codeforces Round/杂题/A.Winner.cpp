#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
string s;
void solve(){
    n = s.size();
    cout << 1 << endl;
    int cur = n, last = n, idx = n - 1;
    for(int i = n - 1; i >= 0; -- i){
        if(s[i] == 1 && cur == n){
            cur = i;
            for(int j = i; j >= 0; -- j){
                if(s[j] == 1)last = j;
                else break;
            }
            break;
        }
    }
    cout << cur << " " << last << endl;
    ll res = 0;
    while(idx > 0){
        res += (cur - idx);
        idx = cur;
        if(!idx)break;
        cur = last - 1;
        for(int j = cur; j >= 0; -- j){
            if(s[j] == 1)last = j;
            else break;
        }
    }
    cout << res << endl;
}
int main(){	
    //cin >> t;
    //while(t -- ){
        cin >> s;
        solve();
    //}
    return 0;
}