#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e8 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

char s[N];
int n;
ll ksm(ll n, ll q){
    ll ans = 1;
    while(q){
        if(q & 1)ans = ans * n % P;
        n = n * n % P;
        q >>= 1;
    }
    return ans;
}
void solve(){
    n = strlen(s + 1);
    ll ans1 = 0, ans2 = 0, ansJ = 0, ansA = 0, ansY = 0;
    for(int i = 1; i <= n; ++ i){
        if(s[i] == 'J' && s[i + 1] == 'a' && s[i + 2] == 'y'){
            i += 2;
            ++ ans1;
        }
        else if(s[i] == 'J'){
            ++ ansJ;
        }
        else if(s[i] == 'a'){
            ++ ansA;
        }
        else if(s[i] == 'y'){
            ++ ansY;
        }
    }
    ans2 = min({ansJ, ansA, ansY});
    if(!ans2){
        if(ans1){
            -- ans1;
            ++ ans2;
        }
    }
    ans2 = ans2 * ksm(2, ans1) % P;
    printf("%lld\n", ans2);
}
int main(){	
    scanf("%s", s + 1);
    solve();
    return 0;
}