/**
  *@filename:糖果
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-12 17:44
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000 + 5;
const int mod = 1e9+7;
const int inf=0x3f3f3f3f;

int n,m,k;
int a[105][22];//存储的口味。
int cnt[22];
int minn;
//最难的就是清除状态了。
void dfs(int index,int ans){
    if(index>n)return;
    //index表示当前正在选index包,cnt表示已经选了多少包。
    bool flag=true;
    for(int i=1;i<=m;i++){
        if(cnt[i]==0)flag=false;
    }
    if(flag){
        minn=min(minn,ans);
    }
    for(int j=1;j<=m;j++){
        cnt[j]+=a[index][j];
    }
    dfs(index+1,ans+1);
    for(int j=1;j<=m;j++){
        cnt[j]-=a[index][j];
    }
    dfs(index+1,ans);
}
void solve(){
    minn=inf;
    dfs(1,0);
    if(minn==inf){
        cout<<-1<<endl;
    }
    else{
        cout<<minn<<endl;
    }
}
int main(){
    while(cin>>n>>m>>k){
        int temp;
        memset(a,0,sizeof(a));
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                cin>>temp;
                a[i][temp]++;
            }
        }
        solve();
    }
    return 0;
}