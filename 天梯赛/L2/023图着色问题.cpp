/**
  *@filename:023图着色问题
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-21 19:29
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 500 + 5;
const int mod = 1e9+7;

int n,m,k,t;//无向图顶点数，边数以及颜色数。待检查的颜色分配方案个数。
int g[maxn][maxn];
void solve(){
}
int main(){
    cin>>n>>m>>k;
    int u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        g[u][v]=g[v][u]=1;
    }
    cin>>t;
    vector<int> color(n+1);
    set<int> ans;
    while(t--){
        color.clear(),ans.clear();
        for(int kase=1;kase<=n;kase++){
            cin>>color[kase];
            ans.insert(color[kase]);
        }
        if(ans.size()!=k){//只能等于不能大于或者小于。
            puts("No");
            continue;
        }
        bool flag=false;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(color[i]==color[j]&&g[i][j]){
                    flag=true;
                    break;
                }
            }
        }
        if(flag)puts("No");
        else puts("Yes");
    }
    solve();
    return 0;
}