#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, x;
ll n;
string s;
void solve(){
    ll ans = s.size();
    for(int i = 0; i < x; ++ i){
        int temp = s[i] - '1';
        if(s.size() < x){
            if(temp == 1)s += s.substr(i + 1);
            if(temp == 2)s += s.substr(i + 1) + s.substr(i + 1);
        }
        ans = (ans + ((ans - i - 1) * temp % P + P)) % P;
    }
    printf("%lld\n", ans % P);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &x);
        cin >> s;
        solve();
    }
    return 0;
}