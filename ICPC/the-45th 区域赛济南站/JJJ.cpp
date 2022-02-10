#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
bool g[110][110];
vector<int> p[2];//二分图。
int color[110];//color[u]表示u所染的颜色
void dfs(int u, int fu, bool op){
    p[op].push_back(u);
    color[u] = op;
    for(int v = 1; v <= n; ++ v){
        if(v == fu)continue;
        if(g[u][v])dfs(v, u, op ^ 1);
    }
}
void solve(){
    dfs(1, -1, 0);
    //因为我们是通过p[0]来构造p[1]。
    if(p[0].size() > p[1].size())swap(p[0], p[1]);
    vector<ll> res(n + 1, (1LL << 60) - 1);
    for(auto u : p[0])res[u] ^= 1;
    for(auto v : p[1])res[v] ^= 2;
    ll x = 4;
    for(auto u : p[0]){
        res[u] ^= x;
        for(auto v : p[1]){
            //将没有联系的且处于不同部的都清除这个点。
            if(!g[u][v] && color[u] != color[v])res[v] ^= x;
        }
        x *= 2;
    }
    for(int i = 1; i <= n; ++ i){
        printf("%lld ", res[i]);
    }
    puts("");
}
int main(){
    scanf("%d", &n);
    for(int i = 1, u, v; i < n; ++ i){
        scanf("%d%d", &u, &v);
        g[u][v] = g[v][u] = true;
    }
    solve();
    return 0;
}