/**
  *@filename:金字塔
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-17 20:20
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 300 + 5;
const int P = 1e9;

string s;//得到的颜色序列。设len，其中树结点有n个。则满足2n-1=len。
//首先我们要发现我们有一个dfs序列，要把它还原成一棵树，有多少中可能？而观察我们可得：
//u->subtree->u
//所以如果是子树，那么子树的开头和子树的结尾要要相等，这样才符合dfs序。
ll f[N][N];
//化零为整，则我们用f[l,r]表示[l,r]区间内的树结构一共有多少中可能。
//所以这实际上是一个递归dp。
int n;//字符串长度。
ll dp(int l,int r){
    //特判递归边界。
    if(l>r)return 0;
    if(l==r)return 1;
    if(f[l][r]!=-1)return f[l][r];//记忆化搜搜。
    f[l][r]=0;
    if(s[l]==s[r]){
        //只有相等才可以划分树。
        //由于已经有了区间，这时候我们只需要枚举分割点就可以。
        for(int k=l+2;k<=r;k++){
            f[l][r]=(f[l][r]+dp(l+1,k-1)*dp(k,r))%P;//这里的意思是[l+1,k-1]是作为第一颗子树。
        }
    }
    return f[l][r];
}
void solve(){
    cout<<dp(0,n-1)<<endl;
}
int main(){
    cin>>s;
    n=s.size();
    fill(f[0],f[0]+N*N,-1);//-1表示没有被计算过。
    solve();
    return 0;
}