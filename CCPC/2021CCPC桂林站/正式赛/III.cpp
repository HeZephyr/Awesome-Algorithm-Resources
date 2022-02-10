#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
char s[N];
void solve(){
    ll res = 0;
    int cnt = 0;
    for(int i = n; i >= 1; -- i){
        if(s[i] == '0')++ cnt;
        else{
            if(cnt){
                res += i;
                -- cnt;
            }
            else{
                ++ cnt;
            }
        }
    }
    printf("%lld\n", res);
}
int main(){	
    int t;
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%s", &n, s + 1);
        solve();
    }
    return 0;
}