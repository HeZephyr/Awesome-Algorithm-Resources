#include<iostream>
#include<string>

using namespace std;

const int maxn=1e5+2;
//定义线段。
struct Segment{
    int l,r;//左右区间。
    int lazy;//lazy标记。
    int valueInfo;//区间表示值。这里以区间和为例。
};
Segment segmentTree[maxn<<2];//线段树。
int n;//树结点个数。
void BuildTree(int st,int l,int r){
    //st表示当前初始化结点编号，l,r表示当前初始区间。
    segmentTree[st].l=l,segmentTree[st].r=r,segmentTree[st].lazy=0;
    if(l==r){
        cin>>segmentTree[st].valueInfo;
        return;
    }
    //先递归构造左子树，再递归构造右子树，最后更新根结点。
    BuildTree(st<<1,l,(l+r)>>1);
    BuildTree(st<<1|1,((l+r)>>1)+1,r);
    segmentTree[st].valueInfo=segmentTree[st<<1].valueInfo+segmentTree[st<<1|1].valueInfo;
}
void PushDown(int st){
    if(segmentTree[st].lazy){
        segmentTree[st<<1].valueInfo+=(segmentTree[st<<1].r-segmentTree[st<<1].l+1)*segmentTree[st].lazy;
        segmentTree[st<<1|1].valueInfo+=(segmentTree[st<<1|1].r-segmentTree[st<<1|1].l+1)*segmentTree[st].lazy;
        segmentTree[st<<1].lazy+=segmentTree[st].lazy;
        segmentTree[st<<1|1].lazy+=segmentTree[st].lazy;
        segmentTree[st].lazy=0;
    }
}
void UpDate(int st,int l,int r,int value){
    //进行区间修改。
    if(segmentTree[st].l==l&&segmentTree[st].r==r){
        segmentTree[st].valueInfo+=(r-l+1)*value;//注意是区间长度。
        segmentTree[st].lazy+=value;//记录lazy标记。
        return;
    }
    //由于要进行左右子树分支，故标记下移。
    PushDown(st);
    int mid=segmentTree[st].l+segmentTree[st].r>>1;
    if(r<=mid){
        //说明全在左子树。
        UpDate(st<<1,l,r,value);
    }
    else if(l>mid){
        //说明全在右子树。
        UpDate(st<<1|1,l,r,value);
    }
    else{
        //各占一半。
        UpDate(st<<1,l,mid,value);
        UpDate(st<<1|1,mid+1,r,value);
    }
}
int Query(int st,int l,int r){
    //需要查询区间[l,r]中的数。
    if(segmentTree[st].l==l&&segmentTree[st].r==r){
        return segmentTree[st].valueInfo;
    }
    //往左右子树搜索。
    PushDown(st);//那么对应标记需要下移。
    int mid=segmentTree[st].l+segmentTree[st].r>>1,ans=0;
    if(r<=mid){
        ans=Query(st<<1,l,r);
    }
    else if(l>mid){
        ans=Query(st<<1|1,l,r);
    }
    else{
        ans=Query(st<<1,l,mid)+Query(st<<1|1,mid+1,r);
    }
    return ans;
}
int main(){
    int n,q;
    while(cin>>n>>q){
        BuildTree(1,1,n);
        string op;
        int a,b,c;
        while(q--){
            cin>>op;
            if(op=="Q"){
                cin>>a>>b;
                cout<<Query(1,a,b)<<endl;
            }
            else{
                cin>>a>>b>>c;
                UpDate(1,a,b,c);
            }
        }
    }
    return 0;
}