#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 +7;
ll sx[maxn], sy[maxn];
struct q_node{
    int op, x;
    ll t;
}Q[maxn];
bool cmp(q_node x, q_node y){
    return x.t > y.t;
}
int main(){
    int n, m, q;
    ll sumx = 0, sumy = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i){
        scanf("%lld", &sx[i]);
        sumx += sx[i];
        sumx %= mod;
    }
    for(int i = 1; i <= m; ++i){
        scanf("%lld", &sy[i]);
        sumy += sy[i];
        sumy %= mod;
    }
    scanf("%d", &q);
    for(int i = 1; i <= q; ++i){
        scanf("%d %d %lld", &Q[i].op, &Q[i].x, &Q[i].t);
    }
    sort(Q + 1, Q + q + 1, cmp);
    //cout << sumx << sumy << endl;
    ll ans = 0;
    for(int i = 1; i <= q; ++i){
        int op = Q[i].op, x = Q[i].x;
        ll t = Q[i].t;
        if(sumx <= 0 || sumy <= 0)break;
        if(op == 1){
            if(sx[x] == -1)continue;
            ans += ((sumy * sx[x] % mod) * (t % mod) % mod);
            ans %= mod;
            sumx = (sumx - sx[x] + mod ) % mod;
            sx[x] = -1;
        }
        else {
            if(sy[x] == -1)continue;
            ans += ((sumx * sy[x] % mod) * (t % mod) % mod);
            ans %= mod;
            sumy = (sumy - sy[x] + mod ) % mod;
            sy[x] = -1;
        }
    }
    printf("%lld", ans);
}