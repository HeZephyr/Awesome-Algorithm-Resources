/**
  *@filename:004这是二叉搜索树吗？
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-20 15:30
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000 + 5;
const int mod = 1e9+7;

//对于二叉排序树，我们可以利用这些特性来实现，左子树的所有结点的值小于小于根结点的值，右子树的所有结点大于根结点的值。
//由于前序遍历是根左右，故左子树的根结点我们很容易就知道，关键在于右子树，我们需要找到右子树的根结点。
//对于排序树，往后比它小的点为它的左子树的点，再往后比它大于等于的点即全为右子树的点。
//
int n,pre[maxn];
vector<int> post;
void getPost(bool isMirror,int root,int tail){
    //root为根，tail为最后一个结点的索引。
    int i=root+1,j=tail;//确定右子树结点。
    if(!isMirror){
        while(i<=tail&&pre[i]<pre[root])i++;//指示右子树根结点。
        //我们还需要表示右子树根结点的前一个结点，因为极限情况下可能没有左子树，此时j=root。
        while(j>root&&pre[j]>=pre[root])j--;
    }
    else{
        //对于镜像序列。其实也好处理，即左边大于等于根结点，右边小于根结点。
        while(i<=tail&&pre[i]>=pre[root])i++;
        while(j>root&&pre[j]<pre[root])j--;
    }   
    //最后j和i必然是相差1，因为i指示右子树根结点。
    if(i-j!=1)return;
    getPost(isMirror,root+1,j);//将左子树的后序遍历加入到post中。
    getPost(isMirror,i,tail);//如果存在右子树，那么加入到post中。
    post.push_back(pre[root]);
}
void solve(){
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>pre[i];
    getPost(false,0,n-1);
    //如果无法满足我们再尝试镜像。
    if(post.size()!=n){
        post.clear();
        getPost(true,0,n-1);
    }
    if(post.size()==n){
        puts("YES");
        for(int i=0;i<n;i++){
            cout<<post[i];
            i==n-1?cout<<endl:cout<<' ';
        }
    }
    else{
        puts("NO");
    }
    solve();
    return 0;
}