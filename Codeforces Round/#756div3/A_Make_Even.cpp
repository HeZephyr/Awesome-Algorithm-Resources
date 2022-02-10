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
    int n = s.size() - 1;
    if((s[n] - '0') % 2 == 0){
        puts("0");
    }
    else if((s[0] - '0') % 2 == 0){
        puts("1");
    }
    else{
        bool flag = false;
        for(int i = 0; i <= n; ++ i){
            if((s[i] - '0') % 2 == 0){
                flag = true;
            }
        }
        if(flag)puts("2");
        else puts("-1");
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> s;
        solve();
    }
    return 0;
}