#include<bits/stdc++.h>

using namespace std;
using ll = long long;
ll t, n, m, ans, p, q;
ll a[505][505];
ll C[1005][1005];
//map<pair<ll,ll>, bool> vis;
const int MOD = 998244353;
void dfs(ll x, ll y, ll c0, ll c1){
    if(x>n || y>m) return;
    //printf("!!! = %lld %lld %lld %lld\n", x, y, c0, c1);
    if(c0>=p && c1>=q){
        //printf("x = %lld, %lld\n", x, y);
        ans = (ans + C[n-x+m-y][n-x])%MOD;
        return;
    }
    else if(max(p-c0, 0ll) + max(q-c1, 0ll) > n-x + m-y){
        return;
    }
    if(a[x+1][y]) dfs(x+1ll, y, c0, c1+1);
    else dfs(x+1ll, y, c0+1, c1);
    if(a[x][y+1]) dfs(x, y+1ll, c0, c1+1);
    else dfs(x, y+1ll, c0+1, c1);
}
int main(){
    scanf("%lld%lld%lld%lld", &n, &m, &p, &q);
    for(ll i = 1;i <= n;i++){
        for(ll j = 1;j <= m;j++){
            scanf("%lld", &a[i][j]);
        }
    }
    for(ll i = 0;i < 1002;i++){
        C[i][0] = C[i][i] = 1;
        for(ll j = 1;j < i;j++)
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
    }
    if(a[1][1])
        dfs(1ll, 1ll, 0ll, 1ll);
    else
        dfs(1ll, 1ll, 1ll, 0ll);
    printf("%lld\n", ans);
    return 0;
}