/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-03 19:37
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5;
const int P = 1e9+7;

int n,m;
int u,v;
vector<int> g[N];
bool check(){
    for(int i = 1; i <= n; ++ i){
        if(g[i].size() != n - 1){
            return true;
        }
    }
    return false;
}
void solve(){
    int cnt = 0;
    vector<int> ans;
    while(check()){
        int maxx = 0,idx;
        for(int i = 1; i <= n; ++ i){
            if(g[i].size() > minn){
                minn = g[i].size();
                idx = i;
            }
        }
         
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++ i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    solve();
    return 0;
}