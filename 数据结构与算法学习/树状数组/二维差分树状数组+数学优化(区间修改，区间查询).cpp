/**
  *@filename:二维差分树状数组+数学优化(区间修改，区间查询)
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-27 19:46
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000 + 5;
const int mod = 1e9+7;

int c1[maxn][maxn],c2[maxn][maxn],c3[maxn][maxn],c4[maxn][maxn];
int n,m;//矩阵大小。
int lowbit(int x){
    return x&(-x);
}
void add(int x,int y,int value){
    for(int i=x;i<=n;i+=lowbit(i)){
        for(int j=y;j<=m;j+=lowbit(j)){
            c1[i][j]+=value;
            c2[i][j]+=x*value;
            c3[i][j]+=y*value;
            c4[i][j]+=x*y*value;
        }
    }
}
int getSum(int x,int y){
    int ans=0;
    //查询左上角为(1,1)右下角为(x,y)的矩阵和。
    for(int i=x;i>0;i-=lowbit(i)){
        for(int j=y;j>0;j-=lowbit(j)){
            ans+=c1[i][j]*(i+1)*(j+1);
            ans-=c2[i][j]*(j+1);
            ans-=c3[i][j]*(i+1);
            ans+=c4[i][j];
        }
    }
    return ans;
}
void solve(){
}
int main(){
    
    solve();
    return 0;
}