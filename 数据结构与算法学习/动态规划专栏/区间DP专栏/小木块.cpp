/**
  *@filename:小木块
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-18 13:14
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200 + 5;
const int P = 1e9+7;

int t,n;//t组测试数据，n个木块。
int a[N];
int f[N][N][N];//f[l][r][k]则表示消除[l,r]这段区间并且连带消除j往后，不包括j长度为k的最大分数。
//常规的状态转移肯定就是f[l,r]=f[l,k]+f[k+1][r]。不过我们还需要考虑连续消去这种情况。
//连续消去的得分为消去的区间长度的平方。
int dp(int l,int r,int k){
    //开始判断。
    int &ans=f[l][r][k];//利用引用更改。
    if(l==r)return ans=(1+k)*(1+k);//由于这里只有一个，所以被消去的有1+k个。
    if(ans>=0){
        //说明这种状态被检索过。
        return ans;
    }
    ans=0;
    //开始判断r前面有多少和r相等的
    int p=r;
    while(p>=l&&a[p]==a[r])p--;
    //当循环终止的时候就是a[p]!=a[r]或者离开区间了，所以我们这里还需要再p++。
    p++;
    if(p==l)return ans=(r-p+1+k)*(r-p+1+k);//说明这种情况就是最大的。
    for(int q=l;q<p;q++){
        if(a[q]==a[r]&&a[q+1]!=a[r]){
            ans=max(ans,dp(l,q,k+r-p+1)+dp(q+1,p-1,0));
        }
    }
    return ans=max(ans,dp(l,p-1,0)+(k+r-p+1)*(k+r-p+1));
}
int main(){
    cin>>t;
    for(int k=1;k<=t;k++){
        cin>>n;
        memset(f,-1,sizeof(f));
        for(int i=1;i<=n;i++)cin>>a[i];
        cout<<"Case "<<k<<": "<<dp(1,n,0)<<endl;
    }
    return 0;
}