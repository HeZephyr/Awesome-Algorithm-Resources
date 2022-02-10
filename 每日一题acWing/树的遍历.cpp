#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

const int N=30+10;

//记录中序遍历的点
vector<int>inorder(N,0);    
//记录后序遍历的点
vector<int>postorder(N,0);  
//记录中序遍历序列每个点的相应位置 第一维表示值 第二维其在中序序列中的具体位置
unordered_map<int,int>pos;
//记录原本的树的信息 第一维为表示树结点的值 第二维表示树节点指向的节点
unordered_map<int,int>l,r;  


//返回值为当前所在节点区间的根
int build(int il,int ir,int pl,int pr){
    int root=postorder[pr];
    int k=pos[root];


    //存在左子树
    if(il<k)
        l[root]=build(il,k-1,pl,pl+(k-1)-il);
    //存在右子树
    if(ir>k)
        r[root]=build(k+1,ir,pl+(k-1-il)+1,pr-1);

    /**
    * 关于递归的区间划分问题
    * 很显然递归的目的是进入左右然后再次寻找根
    * 所以对于中序遍历很简单结合数轴就可以理解
    * 因为k为根节点的位置 所以k左右两边左右子树即对应(il,k-1)(k+1,ir)
    * 而对于后序遍历则稍微要绕一下
    * 由于后序遍历区间的节点数与中序遍历是相等的(这是因为每次划分都是以后序树确定的根为依据)
    * 所以每次划分后 后序树的左右树也会有与中序树相对应的区间范围
    * 即(pl,pl+(k-1)-il)(pl+(k-1-il)+1,pr-1)
    */


    return root;
}

void bfs(int root){
    queue<int>q;
    q.push(root);

    while(q.empty()==false){
        auto t = q.front();
        cout<<t<<' ';
        q.pop();
        if(l.count(t))
            q.push(l[t]);
        if(r.count(t))
            q.push(r[t]);
    }
}


int main(){
    int n;

    cin>>n;

    for(int i=0;i<n;i++)
        cin>>postorder[i];

    for(int i=0;i<n;i++){
        cin>>inorder[i];
        pos[inorder[i]]=i;
    }

    int root=build(0,n-1,0,n-1);

    bfs(root);

    return 0;
}