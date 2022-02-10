#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
vector<ll> a;
int main() {
    scanf("%d", &n);
    for(int i = 0, x; i < n; ++ i){
        scanf("%d", &x);
        a.push_back(x);
    }
    vector<pii> s(1, {0, 0});
    ll res = 0, ans = 0;
    for(int i = 0; i + 1 < n; i += 2){
        ll x = a[i], y = a[i + 1];
        ans += x - y;
        res += min(y, ans + y - s[0].first);
        while(!s.empty() && s.back().first > ans){
            res += s.back().second;
            s.pop_back();
        }
        if(!s.empty() && s.back().first == ans){
            res += s.back().second;
            ++ s.back().second;
        }
        else{
            if(s.empty()){
                s.push_back({ans, 0LL});
            }
            else{
                s.push_back({ans, 1LL});
            }
        }
    }
	printf("%lld\n",res);
}
