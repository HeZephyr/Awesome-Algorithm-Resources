#include<bits/stdc++.h>

using namespace std;

const int maxn=1010;
const int mod = 1e9+7;
int n,m;//物品数量和背包容积。
int v,w;
int dp[maxn],g[maxn];//g数组用来存放当背包体积为i的时候总价值最佳的方案数。
int main(){
    cin>>n>>m;
    //什么不装也是一种方案。
    for(int j=0;j<=m;j++)g[j]=1;
    for(int i=1;i<=n;i++){
        cin>>v>>w;
        for(int j=m;j>=v;j--){
            //更新方案数与最大价值。
            int value=dp[j-v]+w;
            if(value>dp[j]){
                //说明此时我们需要更新方案数。
                dp[j]=value;
                g[j]=g[j-v];
            }
            else if(value==dp[j]){
                //如果总价值相等，说明两种做法都行，相加。
                g[j]=(g[j]+g[j-v])%mod;
            }
        }
    }
    cout<<g[m]<<endl;
    return 0;
}