/**
  *@filename:加分二叉树
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-19 16:35
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 30 + 5;
const int P = 1e9+7;

int n,w[N];
int f[N][N],root[N][N];//f[l][r]表示[l,r]这段区间以k为根节点的集合所获得的最大加分。
void dfs(int l,int r){
    if(l>r)return;
    int k=root[l][r];
    cout<<k<<" ";
    dfs(l,k-1);
    dfs(k+1,r);
}
void solve(){
    //枚举区间长度。
    for(int len=1;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            //枚举根节点。
            for(int k=l;k<=r;k++){
                int left=k==l?1:f[l][k-1];//这里特判是否存在左子树。
                int right=k==r?1:f[k+1][r];//这里特判是否存在右子树。
                int score=left*right+w[k];
                if(l==r){
                    //说明此时不存在左子树和右子树，只有它本身。
                    score=w[k];
                }
                if(f[l][r]<score){
                    root[l][r]=k;
                    f[l][r]=score;
                }
            }
        }
    }
    cout<<f[1][n]<<endl;
    dfs(1,n);//dfs求出前序遍历的结果。
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>w[i];
    solve();
    return 0;
}