/**
  *@filename:发现环(拓扑排序)
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-29 19:32
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//我们需要使用拓扑排序去解决这道题。
int indegree[maxn];//indegree[i]表示的即是顶点i的入度有多少。
bool vis[maxn];//vis[i]表示顶点i是否已经入队。
int n,a,b;
vector<int> g[maxn];
void solve(){
    //现在我们需要去判断哪些点的入队为0.
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==1){
            q.push(i);//由于是无向图，所以我们默认为1的为起点。
            vis[i]=true;
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++){
            if(indegree[g[u][i]]>1){
                indegree[g[u][i]]--;
                if(indegree[g[u][i]]==1){
                    vis[g[u][i]]=true;
                    q.push(g[u][i]);
                }
            }
        }
    }
    bool flag=false;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            //没有入队的说明
            if(!flag){
                //说明是第一次输出。
                cout<<i;
                flag=true;
            }
            else{
                cout<<" "<<i;
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        indegree[a]++,indegree[b]++;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    solve();
    return 0;
}