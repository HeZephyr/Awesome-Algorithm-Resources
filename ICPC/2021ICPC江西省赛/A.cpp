#include<bits/stdc++.h>

using namespace std;
using ll = long long;
ll t, n, m, ans, p, q;
ll nx[5] = {0, 1};
ll ny[5] = {1, 0};
ll a[505][505];
ll fac[505], C[1005][1005];
//map<pair<ll,ll>, bool> vis;
const int MOD = 998244353;
struct node{
    ll x, y, c0, c1;
};
int main(){
    scanf("%lld%lld%lld%lld", &n, &m, &p, &q);
    for(ll i = 1;i <= n;i++){
        for(ll j = 1;j <= m;j++){
            scanf("%lld", &a[i][j]);
        }
    }
    if(n==1 && m==1){
        if(a[1][1] && p==0 && q<=1) printf("1\n");
        else if(a[1][1]==0 && p<=1 && q==0) printf("1\n");
        else printf("0\n");
        return 0;
    }
    for(ll i = 0;i < 1002;i++){
        C[i][0] = C[i][i] = 1;
        for(ll j = 1;j < i;j++)
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
    }
    queue<node> v;
    if(a[1][1]) v.push({1ll, 1ll, 0ll, 1ll});
    else v.push({1ll, 1ll, 1ll, 0ll});
    ll ans = 0ll;
    while(!v.empty()){
        node tem = v.front();
        v.pop();
        for(ll i = 0; i < 2;i++){
            ll tx = tem.x + nx[i];
            ll ty = tem.y + ny[i];
            if(tx>n || ty>m){
                continue;
            }
            //printf("!! tx = %lld , %lld\n", tx, ty);
            node now;
            if(a[tx][ty]){
                now = {tx, ty, tem.c0, tem.c1+1};
            } else{
                now = {tx, ty, tem.c0+1, tem.c1};
            }
            if(now.c0>=p && now.c1>=q){
                //printf("tx = %lld %lld\n", tx, ty);
                ans = (ans + C[n-tx+m-ty][n-tx])%MOD;
            }
            else if(max(p-now.c0, 0ll) + max(q-now.c1, 0ll) <= n-tx + m-ty){
                v.push(now);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}