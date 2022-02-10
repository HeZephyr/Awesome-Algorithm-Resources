/**
  *@filename:油漆面积
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-30 23:19
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 10000 + 5;
const int mod = 1e9+7;

int n;
int min_x,min_y,max_x,max_y;
bool vis[maxn][maxn];
void solve(){
    int ans=0;
    for(int i=min_x;i<=max_x;i++){
        for(int j=min_y;j<=max_y;j++){
            ans+=vis[i][j];
        }
    }
    cout<<ans<<endl;
}
int main() {
    int x1,y1,x2,y2;
    while(cin>>n){
        min_x=100000,min_y=100000,max_x=0,max_y=0;
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++){
            cin>>x1>>y1>>x2>>y2;
            min_x=min(min(x1,x2),min_x);
            min_y=min(min(y1,y2),min_y);
            max_x=max(max(x1,x2),max_x);
            max_y=max(max(y1,y2),max_y);
            for(int i=x1;i<x2;i++){
                for(int j=y1;j<y2;j++){
                    vis[i][j]=true;
                }
            }
        }
        solve();
    } 
    return 0;
}