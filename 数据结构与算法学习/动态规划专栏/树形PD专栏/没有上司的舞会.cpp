/**
  *@filename:没有上司的舞会
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-19 21:30
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000000 + 5;
const int P = 1e9+7;

int n,root;//root代表根结点。
int f[N][2];
//我们可以定义f(i,0/1)来表示以i为根的子树的最优解，其中第二维0代表i不参加舞会的情况，1代表参加舞会的情况。
//其中我们需要知道只要上司参加了，那么直接下属绝对不参加。我们假设x是i的儿子，则f(i,1)=\sum f(x,0)+a[i];
int a[N];
bool vis[N];//判断结点是否有直接上司，没有的自然是根结点。
vector<int> edges[N];
void dfs(int root){
    f[root][0]=0;//不选择自己。
    f[root][1]=a[root];//选择自己。
    for(int i=0;i<edges[root].size();i++){
        //遍历它们的儿子。
        int son=edges[root][i];
        dfs(son);
        f[root][0]+=max(f[son][0],f[son][1]);
        f[root][1]+=f[son][0];
    }
}
void solve(){
    dfs(root);
    cout<<max(f[root][1],f[root][0])<<endl;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int l,k;
    for(int i=1;i<=n-1;i++){
        scanf("%d%d",&l,&k);
        edges[k].push_back(l);
        vis[l]=true;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            root=i;
            break;
        }
    }
    solve();
    return 0;
}