/**
  *@filename:数字游戏
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-18 17:30
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 110,M=10,INF = 0x3f3f3f;
const int P = 1e9+7;

int n,m;
int dpMax[N][N][M],dpMin[N][N][M];
//其中dpMax[l][r][k]表示将[l,r]这部分区间分成k部分的最大值。dpMin同理。
int s[N];//前缀和，方便快速求解一段区间的和。
int mod(int x){
    return (x%10+10)%10;
}
void solve(){
    fill(dpMax[0][0],dpMax[0][0]+N*N*M,-INF);
    fill(dpMin[0][0],dpMin[0][0]+N*N*M,INF);
    for(int len=1;len<=n;len++){
        for(int l=1;l+len-1<=2*n;l++){
            int r=l+len-1;
            dpMax[l][r][1]=dpMin[l][r][1]=mod(s[r]-s[l-1]);
            //枚举剩余次数。
            for(int k=2;k<=m;k++){
                //枚举分割点。
                for(int j=l+k-2;j<r;j++){
                    dpMax[l][r][k]=max(dpMax[l][r][k],dpMax[l][j][k-1]*mod(s[r]-s[j]));
                    dpMin[l][r][k]=min(dpMin[l][r][k],dpMin[l][j][k-1]*mod(s[r]-s[j]));
                }
            }
        }
    }
    int maxx=-INF,minn=INF;
    for(int i=1;i<=n;i++){
        maxx=max(dpMax[i][i+n-1][m],maxx);
        minn=min(dpMin[i][i+n-1][m],minn);
    }
    cout<<minn<<endl;
    cout<<maxx<<endl;
}
int main(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>s[i];
        s[i+n] = s[i];
    }
    //求前缀和。
    for(int i = 1; i <= 2*n; i++){
        s[i] += s[i-1];
    }
    solve();
    return 0;
}