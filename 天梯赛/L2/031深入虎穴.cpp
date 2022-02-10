/**
  *@filename:031深入虎穴
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-22 18:12
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,k,u;//门的数量。
vector<vector<int> > g;//邻接表。
bool vis[maxn];//入口就是没有门进入的点。
int maxx,ed;//标记最选的那个门
void dfs(int door,int step){
    if(g[door].size()==0){
        //说明为不能往下走了，我们记录。
        if(step>maxx){
            maxx=step,ed=door;
        }
    }
    for(int i=0;i<g[door].size();i++){
        dfs(g[door][i],step+1);
    }
}
void solve(){
    //从入口选择进行dfs递归求最大值。
    int st;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            st=i;
            break;
        }
    }
    maxx=-1;
    dfs(st,0);
    cout<<ed<<endl;
}
int main(){
    cin>>n;
    g.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>k;
        while(k--){
            cin>>u;
            vis[u]=true;
            g[i].push_back(u);
        }
    }
    solve();
    return 0;
}