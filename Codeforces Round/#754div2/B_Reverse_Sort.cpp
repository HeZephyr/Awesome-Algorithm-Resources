#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n;
string s;
vector<int> g[N];
int len;
void solve(){
    int len = 0;
    while(true){
        int l = 0, r = n - 1, cnt = 0;
        g[len].clear();
        while(l < r){
            while(s[l] == '0')++ l;
            while(s[r] == '1')-- r;
            if(l > r)break;
            g[len].push_back(l), g[len].push_back(r);
            ++ l, -- r;
            ++ cnt;
        }
        int x = g[len].size();
        if(cnt == 0)break;
        sort(g[len].begin(), g[len].end());
        for(int i = 0; i < x / 2; ++ i){
            swap(s[g[len][i]], s[g[len][x - i - 1]]);
        }
        ++ len;
    }
    cout << len << endl;
    for(int i = 0; i < len; ++ i){
        cout << g[i].size() << " ";
        for(int j = 0; j < g[i].size(); ++ j){
            cout << g[i][j] + 1 << " ";
        }
        cout << endl;
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n >> s;
        len = 0;
        solve();
    }
    return 0;
}