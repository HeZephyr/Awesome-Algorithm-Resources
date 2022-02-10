#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6 + 10;
int t, n, dep[N];
vector<int> g[N];
bool cmp(int i, int j){
    return dep[i] < dep[j];
}
void dfs1(int u, int fu){
    for(auto v : g[u]){
        if(v == fu)continue;
        dep[v] = dep[u] + 1;
        dfs1(v, u);
    }
    sort(g[u].begin(), g[u].end(), cmp);
}
int solve(){
    dfs1(1, 0);
    int res = 0;
    for(int i = 1; i <= n; ++ i){
        for(auto v : g[i]){
            cout << i << "->" << v << " " << dep[v] << endl;
        }
    }
    return res;
}
int main(){
    scanf("%d", &t);
    for(int k = 1; k <= t; ++ k){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            g[i].clear();
        }
        for(int i = 2, u, v; i <= n; ++ i){
            scanf("%d", &v);
            u = i;
            g[u].push_back(v), g[v].push_back(u);
        }
        printf("Case #%d: %d\n", k, solve());
    }
    return 0;
}