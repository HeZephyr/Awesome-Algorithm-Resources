#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, t;
string s;
void solve(){
    int cnt = 0, maxx = 0;
    for(int i = 0; i < n; ++ i){
        if(s[i] == '1'){
            ++ cnt;
        }
        else{
            maxx = max(maxx, cnt);
            cnt = 0;
        }
    }
    maxx = max(maxx, cnt);
    if(maxx >= t){
        puts("Yes");
    }
    else{
        puts("No");
    }
}
int main(){	
    cin >> n >> t;
    cin >> s;
    solve();
    return 0;
}