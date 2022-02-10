/**
  *@filename:006树的遍历
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-20 16:29
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100 + 5;
const int mod = 1e9+7;

int n;
int in[maxn],post[maxn];//中序遍历和后序遍历。
//递归求解出二叉树结构。
struct node{
    int lson,rson;//左右子树。
    int value;//结点权值。
}tree[maxn];
int build(int lmid,int rmid,int lpost,int rpost){
    //通过中序遍历和后序遍历确定根。
    if(lmid>rmid)return 0;
    int root=rpost;//后序遍历确定根。
    int fa=lmid;
    while(in[fa]!=post[root])fa++;//寻找中序遍历的根，确保分割左右子树。
    int len=fa-lmid;//确定左子树的长度。
    //递归分割。
    tree[root].value=post[root];
    tree[root].lson=build(lmid,fa-1,lpost,lpost+len-1);//左子树。
    tree[root].rson=build(fa+1,rmid,lpost+len,rpost-1);//右子树。
    return root;
}
void bfs(int root){
    queue<int> q;
    q.push(root);
    vector<int> result;
    while(!q.empty()){
        int head=q.front();
        q.pop();
        result.push_back(tree[head].value);
        if(tree[head].lson)q.push(tree[head].lson);
        if(tree[head].rson)q.push(tree[head].rson);
    }
    for(int i=0;i<n;i++){
        cout<<result[i];
        i==n-1?cout<<endl:cout<<' ';
    }
}
void solve(){
    int root=n;
    build(1,n,1,n);//建造树。
    //利用bfs跑树。
    bfs(root);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&post[i]);
    for(int i=1;i<=n;i++)scanf("%d",&in[i]);
    solve();
    return 0;
}