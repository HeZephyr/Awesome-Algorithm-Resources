#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e3 + 10;
int n, m, tot, c, sum[N];
bool vis[N];
vector<int> g[N];
map<pair<int,int>, int> mp;
int f[N];
int Find(int x){
    if(x==f[x]) return x;
    else return f[x] = Find(f[x]);
}
int main(){
    scanf("%d%d%d", &n, &m, &c);
    int Mi = INT_MAX;
    for(int i = 1, u, v, w;i <= m;i++){
        scanf("%d%d%d", &u, &v, &w);
        Mi = min(Mi, w);
        if(!mp[{u, v}]) mp[{u,v}] = w;
        else mp[{u, v}] = min(mp[{u, v}], w);
        g[u].push_back(v);
    }
    int Min = INT_MAX;
    for(int i = 1;i <= n;i++) f[i] = i;
    for(int i = 1;i <= n;i++){
        if(g[i].empty()) continue;
        vis[i] = 1;
        for(int j = 0;j < g[i].size();j++){
            int x = g[i][j];
            int fx = Find(x), fi = Find(i);
            if(x<i){
                if(vis[x] && fx==fi)
                    Min = min(Min, sum[i]-sum[x] + mp[{i, x}]);
                continue;
            }
            if(fx!=fi){
                f[fx] = fi;
            }
            if(!sum[x]) sum[x] = sum[i] + mp[{i, x}];
            else sum[x] = min(sum[x], sum[i] + mp[{i, x}]);
        }
    }
    if(c>=Min){
        printf("2\n");
    }
    else if(c >= Mi){
        printf("1\n");
    } else {
        printf("0\n");
    }
    return 0;
}