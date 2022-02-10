/**
  *@filename:二维差分树状数组
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-27 18:39
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000 + 5;
const int mod = 1e9+7;

int n,m;
int d[maxn][maxn];
int lowbit(int x){
    return x&(-x);
}
void add(int x,int y,int value){
    for(int i=x;i<=n;i+=lowbit(i)){
        for(int j=y;j<=m;j+=lowbit(j)){
            d[i][j]+=value;
        }
    }
}
void get(int x,int y){
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i)){
        for(int j=y;j>0;j-=lowbit(j)){
            ans+=d[i][j];
        }
    }
}
void solve(){
}
int main(){
    
    solve();
    return 0;
}