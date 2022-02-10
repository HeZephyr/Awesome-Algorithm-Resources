#include<bits/stdc++.h>

using namespace std;

const int maxn=1e3+5;
int n,V,M;//m表示背包体积，s表示所能承受的最大重量。
int v[maxn],m[maxn],w[maxn];
/* 
//朴素做法，空间未优化。
int dp[maxn][105][105];
int main(){
    cin>>n>>V>>M;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>m[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=V;j++){
            for(int k=0;k<=M;k++){
                dp[i][j][k]=dp[i-1][j][k];
                if(j>=v[i]&&k>=m[i]){
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-v[i]][k-m[i]]+w[i]);
                }
            }
        }
    }
    cout<<dp[n][V][M]<<endl;
    return 0;
} 
*/
//优化空间做法，这里和01背包差不多同样的性质，为了每次利用的都是上一层的状态，我们需要让V->v[i],M->m[i]。
int dp[maxn][maxn];
int main(){
    cin>>n>>V>>M;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>m[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=V;j>=v[i];j--){
            for(int k=M;k>=m[i];k--){
                dp[j][k]=max(dp[j][k],dp[j-v[i]][k-m[i]]+w[i]);
            }
        }
    }
    cout<<dp[V][M]<<endl;
    return 0;
}