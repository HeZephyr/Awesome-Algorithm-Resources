/**
  *@filename:分考场
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-07 20:12
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100 + 5;
const int mod = 1e9+7;

int n,m,u,v;
int g[maxn][maxn];//参考人员的关系。
int f[maxn][maxn],cnt[maxn];//f[i][j]表示第i个考场第j个人的编号。cnt[i]表示的是第i个考场的人数。
int minn=maxn;
void dfs(int idx,int ans){
    //idx为当前正在排的人，ans则为有ans个考场。
    if(ans>=minn)return;//剪枝。
    if(idx==n+1){
        //说明前n个人已经排完了。
        minn=min(ans,minn);
        return;
    }
    //开始为这idx分考场。
    for(int i=1;i<=ans;i++){
        int len=cnt[i];//获得该考场的人数。
        bool flag=false;
        for(int j=1;j<=len;j++){
            if(g[idx][f[i][j]]){
                //说明认识，我们不能放入该考场。
                flag=true;
                break;
            }
        }
        if(!flag){
            //说明可以放入该考场。
            f[i][++cnt[i]]=idx;
            dfs(idx+1,ans);
            cnt[i]--;//回溯。
        }
    }
    f[ans+1][++cnt[ans+1]]=idx;
    dfs(idx+1,ans+1);
    cnt[ans+1]--;//回溯。
}
void solve(){
    dfs(1,0);
    cout<<minn<<endl;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        g[u][v]=g[v][u]=1;//代表有关联。
    }
    solve();
    return 0;
}