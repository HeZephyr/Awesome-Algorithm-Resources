/**
  *@filename:035完全二叉树的层序遍历
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-22 21:35
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 30 + 5;
const int mod = 1e9+7;

int n,idx;//树中结点的个数。
int post[maxn];//后序遍历结果。
int tree[maxn];
void build(int u){
    //u为根结点。
    if(u>n)return;
    build(u<<1);//建立左子树。
    build(u<<1|1);//建立右子树。
    tree[u]=post[++idx];
}
int main(){
    cin>>n;
    idx=0;
    for(int i=1;i<=n;i++)cin>>post[i];
    //完全二叉树可以唯一确定一棵树。我们按其建立树即可。
    build(1);
    for(int i=1;i<=n;i++){
        cout<<tree[i];
        i==n?cout<<endl:cout<<' ';
    }
    return 0;
}