#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
string s[N];
void solve(){
    int cnt = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= 4; ++ j){
            if(s[i][j] == '-')++ cnt;
        }
    }
    cout << cnt << endl;
}
int main(){	
    cin >> n;
    getchar();
    for(int i = 1; i <= n; ++ i){
        getline(cin, s[i]);
    }
    solve();
    return 0;
}