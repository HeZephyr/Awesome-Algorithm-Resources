#include<bits/stdc++.h>

using namespace std;

const int maxn=1e7+5;

//只能处理数据量不大的情况
int n,m;//物品种类数和背包体积。
int v[maxn],w[maxn],s[maxn];//s[i]表示i类物品数量
//多重背包问题我们可以转化为01背包问题求解。
int dp[maxn];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i]>>s[i];
    }
    //处理转化为01背包。
    for(int i=1;i<=n;i++){
        while(s[i]>1){
            v[++n]=v[i];
            w[n]=w[i];
            s[i]--;
            s[n]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(!s[i])continue;
        for(int j=m;j>=v[i];j--){
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}