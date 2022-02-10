#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
const int N = 1e6 + 10;
int n;
ll a[N];
vector<pair<ll, ll> > s;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
    }
    s.push_back({0LL, 0LL});
    int len = 1;
    ll res = 0, ans = 0;
    for(int i = 1; i + 1 <= n; i += 2){
        ans += (a[i] - a[i + 1]);
        res += min(ans + a[i + 1] - s[0].x, a[i + 1]);
        while(len > 0 && s[len - 1].x > ans){
            res += s[len - 1].y;
            s.pop_back();
            -- len;
        }
        if(len > 0 && s[len - 1].x == ans){
            res += s[len - 1].y;
            s[len - 1].y ++;
        }
        else{
            if(len == 0){
                s.push_back({ans, 0LL});
            }
            else{
                s.push_back({ans, 1LL});
            }
            ++ len;
        }
    }
    printf("%lld\n", res);
    return 0;
}