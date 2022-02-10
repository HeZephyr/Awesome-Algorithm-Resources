/**
  *@filename:数组操作
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-02 19:44
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

struct Tree{
    int l,r;//左右区间。
    ll sum;//该区间的和
    int lazy;//lay标记。
}tree[maxn<<2];
void buildTree(int rt,int l,int r){
    tree[rt].l=l,tree[rt].r=r,tree[rt].lazy=0;
    if(l==r){
        //说明到了叶子结点，输入值。
        cin>>tree[rt].sum;
    }
    //递归建立左右子树。
    buildTree(rt<<1,l,(l+r)>>1);
    buildTree(rt<<1|1,((l+r)>>1)+1,r);
    tree[rt].sum=tree[rt<<1].sum+tree[rt<<1|1].sum;
}
void pushDown(int rt){
    //lazy标记下移。
    if(tree[rt].lazy){
        tree[rt<<1].lazy+=tree[rt].lazy;
        tree[rt<<1|1].lazy+=tree[rt].lazy;
        //清除该结点的lazy标记。
        tree[rt<<1].sum+=(tree[rt<<1].r-tree[rt<<1].l+1)*tree[rt].lazy;
        tree[rt<<1|1].sum+=(tree[rt<<1|1].r-tree[rt<<1|1].l+1)*tree[rt].lazy;
        tree[rt].lazy=0;
    }
}
void upDate(int rt,int value,int l,int r){
    if(tree[rt].l==l&&tree[rt].r==r){
        //说明区间符合，我们标记。
        tree[rt].lazy+=value;
        tree[rt].sum+=(tree[rt].r-tree[rt].l+1)*value;
        return;//停止递归。
    }
    if(tree[rt].l==tree[rt].r){
        //到了叶子结点，不能往下了，直接返回。
        return;
    }
    pushDown(rt);//标记下移。因为我们没有区间全覆盖，还需要去寻找左右孩子。
    int mid=(tree[rt].l+tree[rt].r)/2;
    if(r<=mid){
        //更新区间全部在做孩子。
        upDate(rt<<1,value,l,r);
    }
    else if(l>mid){
        //更新区间全在右孩子。
        upDate(rt<<1|1,value,l,r);
    }
    else{
        //否则左右区间均有。
        upDate(rt<<1,value,l,mid);
        upDate(rt<<1|1,value,mid+1,r);
    }
    tree[rt].sum=tree[rt<<1].sum+tree[rt<<1|1].sum;
}
ll query(int rt,int l,int r){
    //区间查询。
    if(tree[rt].l==l&&tree[rt].r==r){
        return tree[rt].sum;
    }
    pushDown(rt);
   	int mid=(tree[rt].r+tree[rt].l)>>1;
  	ll ans=0;
  	if(r<=mid){
  		//说明全部在左孩子
  		ans+=query(rt<<1,l,r);
  	}
  	else if(l>mid){
  		//说明全部在右孩子
  		ans+=query(rt<<1|1,l,r);
  	}
  	else{
  		ans+=query(rt<<1,l,mid);
  		ans+=query(rt<<1|1,mid+1,r);
  	}
  	return ans;
}
void solve(){
}
int main(){
    
    solve();
    return 0;
}