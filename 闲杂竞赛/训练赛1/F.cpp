/**
  *@filename:F
  *@author: pursuit
  *@created: 2021-08-08 20:10
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m,u,v,ans;
int cnt[N],flag;
bool vis[N];
vector<int> g[N];
void dfs(int u,int fu){
    vis[u] = true;
    if(cnt[u] != 2){
        flag = 0;
    }
    for(auto &v : g[u]){
        if(v == fu || vis[v])continue;
        dfs(v,fu);
    }
}
void solve(){
    for(int i = 1; i <= n; ++ i){
        if(!vis[i]){
            flag = 1;
            dfs(i,-1);
            ans += flag;
        }
    }
    printf("%d\n", ans);
}
int main(){	
    scanf("%d%d", &n,&m);
    for(int i = 0; i < m; ++ i){
        scanf("%d%d", &u, &v);
        g[u].push_back(v),g[v].push_back(u);
        cnt[u] ++,cnt[v] ++;
    }
    solve();
    return 0;
}