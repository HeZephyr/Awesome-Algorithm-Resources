/**
  *@filename:020功夫传人
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-21 15:23
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;//整个师门的总人数。
double z,r;//祖师爷的功力值和折扣百分比值。
double result;
bool vis[maxn];//vis[i]表示i是否为得道者。
vector<vector<int> > g;
void dfs(int index,double power){
    //当前所处传人，power代表此人的功力值。
    if(vis[index]){
        //说明为传道者，我们直接累加即可。
        result+=power*g[index][0];
        return;
    }
    for(int i=0;i<g[index].size();i++){
        dfs(g[index][i],power*(1-r/100));
    }
}
void solve(){
    result=0.0;
    dfs(0,z);
    cout<<int(result)<<endl;
}
int main(){
    cin>>n>>z>>r;
    int k,temp;
    g.resize(n);
    for(int i=0;i<n;i++){
        cin>>k;
        if(k==0){
            cin>>temp;
            g[i].push_back(temp);
            vis[i]=true;//为得道者。
        }
        else{
            for(int j=0;j<k;j++){
                cin>>temp;
                g[i].push_back(temp);
            }
        }
    }
    solve();
    return 0;
}