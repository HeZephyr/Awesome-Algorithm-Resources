/**
  *@filename:二维树状数组
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-26 22:03
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000 + 5;
const int mod = 1e9+7;

int n,m;//矩阵长和宽。
int q;//q次询问。
int c[maxn][maxn];
int lowbit(int x){
    return x&(-x);
}
void add(int x,int y,int value){
    //在(x,y)处增加value.
    for(int i=x;i<=n;i+=lowbit(i)){
        for(int j=y;j<=n;j+=lowbit(j)){
            c[i][j]+=value;
        }
    }
}
int getSum(int x,int y){
    //如果求解[x1,y1]~[x2,y2]之间的和，那么就是getSum(x2,y2)-getSum(x2,y1)-getSum(x1,y2)+getSum(x1,y1).
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i)){
        for(int j=y;j>0;j-=lowbit(j)){
            ans+=c[i][j];
        }
    }
    return ans=0;
}
void solve(){
}
int main(){
    
    solve();
    return 0;
}