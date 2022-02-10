/**
  *@filename:025分而治之
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-21 20:20
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//此题就是在攻城完后不存在兄弟城了，所以我们需要去存储兄弟城。
int n,m,k,np;
int friends[maxn],cur_friends[maxn];
bool check(){
    bool flag=false;
    for(int i=1;i<=n;i++){
        if(cur_friends[i]>0){
            flag=true;
            break;
        }
    }
    return flag;
}
int main(){
    int u,v;
    cin>>n>>m;
    vector<vector<int> > g(n+1);
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        friends[u]++,friends[v]++;
    }
    cin>>k;
    while(k--){
        cin>>np;
        for(int i=1;i<=n;i++)cur_friends[i]=friends[i];
        for(int i=0;i<np;i++){
            cin>>u;
            //由于此城被攻占，故没有兄弟城了。
            cur_friends[u]=0;
            for(int j=0;j<g[u].size();j++){
                cur_friends[g[u][j]]--;
            }
        }
        if(check())puts("NO");
        else puts("YES");
    }
    return 0;
}