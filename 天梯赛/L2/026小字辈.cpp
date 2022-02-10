/**
  *@filename:小字辈
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-21 20:41
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;
int root;
int step[maxn];
vector<vector<int> > g;//建立邻接表，如果没有边，说明到了最小辈分了。
//跑bfs。
void bfs(int root){
    queue<int> q;
    vector<int> result;
    int maxx=0;
    step[root]=1;
    q.push(root);
    while(!q.empty()){
        int head=q.front();
        q.pop();
        if(g[head].size()==0){
            if(step[head]>maxx){
                maxx=step[head];
                result.clear();
                result.push_back(head);
            }
            else if(step[head]==maxx){
                result.push_back(head);
            }
        }
        for(int i=0;i<g[head].size();i++){
            q.push(g[head][i]);
            step[g[head][i]]=step[head]+1;
        }
    }
    cout<<maxx<<endl;
    sort(result.begin(),result.end());
    for(int i=0;i<result.size();i++){
        cout<<result[i];
        i==result.size()-1?cout<<endl:cout<<' ';
    }
}
void solve(){
    bfs(root);
}
int main(){
    cin>>n;
    g.resize(n+1);
    int u,v;
    for(int i=1;i<=n;i++){
        cin>>u;
        if(u==-1)root=i;
        else{
            g[u].push_back(i);
        }
    }
    solve();
    return 0;
}