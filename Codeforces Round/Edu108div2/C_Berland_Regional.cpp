/**
  *@filename:C_Berland_Regional
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-29 23:11
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 200000 + 5;
const int mod = 1e9+7;

int t,n;//n为大学数量和学生数量。
vector<ll> g[maxn];//存储。
ll ans[maxn],u[maxn];
void solve(){
    for(int i=1;i<=n;i++){
        sort(g[i].begin(),g[i].end(),greater<int>() );
    }
    //前缀和。
    for(int i=1;i<=n;i++){
        for(int j=1;j<g[i].size();j++){
            g[i][j]+=g[i][j-1];//前缀和
        }
    }
    //对每个学校枚举k，k即为它们的最大成员数。
    for(int i=1;i<=n;i++){
        int k=g[i].size();
        for(int j=1;j<=k;j++){
            ans[j]+=g[i][k-k%j-1];//除去余数。
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i];
        i==n?cout<<endl:cout<<" ";
    }
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        int temp;
        for(int i=1;i<=n;i++){
            cin>>u[i];
            g[i].clear();
            ans[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>temp;
            g[u[i]].push_back(temp);
        }
        solve();
    }
    return 0;
}