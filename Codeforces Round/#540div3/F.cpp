/**
  *@filename:F
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-27 19:02
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 300000 + 5;
const int P = 1e9+7;

int n,a[N],r[N],b[N];
vector<int> g[N];
ll ans;
void dfs(int u,int fu){
    if(a[u] == 1){
        r[u] ++;
    }
    else if(a[u] == 2){
        b[u] ++;
    }
    for(auto &v : g[u]){
        if(v != fu){
            dfs(v,u);
            //将子节点的数量加起来。
            b[u] += b[v];
            r[u] += r[v];
            if(b[v] == b[0] && !r[v] || r[v] == r[0] && !b[v]){
                ans ++;
            }
        }
    }
}
void solve(){
    dfs(1,0);
    cout << ans << endl;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        //1：red 2：blue
        //统计所有的红蓝结点数，相当于0是祖先。
        if(a[i] == 1){
            r[0] ++;
        }
        else if(a[i] == 2){
            b[0] ++;
        }
    }
    int u,v;
    for(int i = 1; i < n; ++ i){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    solve();
    return 0;
}