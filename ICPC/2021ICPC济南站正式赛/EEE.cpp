#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+7;
const int N = 1e3 + 10;

int t, n;
vector<int> g[N];
int siz[N];
bool cmp(int i, int j){
    return siz[i] < siz[j];
}
void dfs1(int u, int fu = 0){
    siz[u] = 1;
    for(auto v : g[u]){
        if(v == fu)continue;
        dfs1(v, u);
        siz[u] += siz[v];
    }
    sort(g[u].begin(), g[u].end(), cmp);
}
int ans, cnt;
void dfs2(int u, int fu){
    ans += cnt;
    for(auto v : g[u]){
        if(v == fu)continue;
        cnt++;
        dfs2(v, u);
    }
    cnt++;
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        ans = cnt = 0;
        for(int i = 1; i <= n; ++ i){
            g[i].clear();
        }
        for(int i = 1, u, v; i < n; ++ i){
            scanf("%d%d", &u, &v);
            g[u].push_back(v), g[v].push_back(u);
        }
        dfs1(1);
        dfs2(1, 0);
        printf("%.10lf\n", 1.0 * ans / (n - 1));
    }
    return 0;
}