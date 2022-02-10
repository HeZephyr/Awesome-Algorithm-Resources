#include<bits/stdc++.h>

using namespace std;

const int maxn=2010;
int n,m;//物品数量和背包统计。
int v[maxn],w[maxn],dp[maxn][maxn];//dp[i][j]表示的即是前i个物品体积不超过j的最大价值。
//由于我们的01背包问题是选与不选，所以我们写出方案数的时候我们就可以比较前后状态来看了。
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    //为了之后能判断字典序最小，所以我们可以从后往前看。
    for(int i=n;i>=1;i--){
        for(int j=0;j<=m;j++){
            dp[i][j]=dp[i+1][j];
            if(j>=v[i])dp[i][j]=max(dp[i][j],dp[i+1][j-v[i]]+w[i]);
        }
    }
    //我们从小到大遍历。
    int res=m;
    for(int i=1;i<=n;i++){
        if(res>=v[i]&&dp[i][res]==dp[i+1][res-v[i]]+w[i]){
            //要注意判断是否越界。这里一定要注意判断是否越界，即空间并不够用了v[i]了。
            cout<<i<<" ";
            res-=v[i];
        }
    }
    cout<<endl;
    return 0;
}