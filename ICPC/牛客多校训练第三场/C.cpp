/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-26 20:42
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2000 + 5;
const int P = 1e9+7;

int n,m,k;//m表示m个位置可以填整数。
int b[N],c[N];
bool vis[N];//vis[i]表示i当前是否已配对
int match[N];//match为匹配数组，。
ll ans;//ans代表最小花费。初值为b和c的总和。
vector<int> g[N];//建图。
bool dfs(int u){
    for(auto &v : g[u]){
        if(!vis[v]){
            //如果当前没有被确定。
            vis[v] = true;
            if(!match[v] || dfs(match[v])){
                //如果没有被匹配或者可以谦让。
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}
void solve(){
    int u,v;//坐标点，看成是两点顶点相连。
    while(m -- ){
        scanf("%d%d", &u, &v);
        if(b[u] == c[v]){
            g[u].push_back(v);//对行建立于列的边。
        }
    }
    //即建立最大匹配。
    for(int i = 1; i <= n; ++ i){
        memset(vis,0,sizeof(vis));
        dfs(i);
    }
    for(int i = 1; i <= n; ++ i){
        if(match[i]){
            ans -= c[i];
        }
    }
    printf("%lld\n",ans);
}
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &b[i]);
        ans += b[i];
    }
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &c[i]);
        ans += c[i];
    }
    solve();
    return 0;
}