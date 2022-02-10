#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, u, v, Max, k;
vector<int> g[110];
ll a[110], cnt[3];
int flag[110];
void dfs(ll u, ll fu, ll x){
    //flag[u] = x;
    cnt[x%2]++;
    for(auto v : g[u]){
        if(v == fu)continue;
        dfs(v, u, x + 1);
    }
}
void df(ll u, ll fu, ll x){
    //flag[u] = x;
    for(auto v : g[u]){
        if(v == fu)continue;
        df(v, u, x + 1);
    }
    if(x%2 && cnt[1]<=cnt[0]){
        a[u] = Max - (1ll << k);
        k++;
    }
    if(x%2==0 && cnt[0]<cnt[1]){
        a[u] = Max - (1ll << k);
        k++;
    }
}
int main(){
    cin >> n;
    k = 1ll;
    Max = (1ll<<60)-1ll;
    for(ll i = 1; i < n; ++ i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1, 1);
    df(1, -1, 1);
    for(ll i = 1;i <= n;i++){
        if(a[i]) continue;
        for(auto it:g[i]){
            a[i] += a[it] ^ Max;
        }
    }
    //printf("cnt = %lld %lld\n", cnt[0], cnt[1]);
    for(ll i = 1;i <= n;i++){
        printf("%lld ", a[i]);
    }
    return 0;
}