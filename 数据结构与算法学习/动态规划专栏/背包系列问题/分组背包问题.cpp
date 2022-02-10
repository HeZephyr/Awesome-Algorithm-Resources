#include<bits/stdc++.h>
#define v first
#define w second
using namespace std;

typedef pair<int,int> pii;
//dp[i][j]表示前i个组，体积不超过j的最大价值。
//则我们在进行状态计算的时候和01背包差不了不少，即是dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[k]]+w[k])k属于第i个组的物品。
//进行状态转移即可。
int n,m;//物品组数和背包容量。
vector<pii> things[105];
/* //朴素做法。
int dp[105][105];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int temp,a,b;
        cin>>temp;
        for(int j=1;j<=temp;j++){
            cin>>a>>b;
            things[i].push_back({a,b});
        }
    }
    //存储好之后就是跟01背包差不多了
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            dp[i][j]=dp[i-1][j];
            for(int k=0;k<things[i].size();k++){
                if(j>=things[i][k].v){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-things[i][k].v]+things[i][k].w);
                }
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
} */
//空间优化，和01背包相同。
int dp[105];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int temp,a,b;
        cin>>temp;
        for(int j=1;j<=temp;j++){
            cin>>a>>b;
            things[i].push_back({a,b});
        }
    }
    //存储好之后就是跟01背包差不多了
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            for(int k=0;k<things[i].size();k++){
                if(j>=things[i][k].v){
                    dp[j]=max(dp[j],dp[j-things[i][k].v]+things[i][k].w);
                }
            }
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}