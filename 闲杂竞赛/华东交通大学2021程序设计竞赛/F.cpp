#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m;
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
        segmentTree[st<<1].valueInfo = 0;
        segmentTree[st<<1|1].valueInfo = 0;
        segmentTree[st<<1].lazy+=segmentTree[st].lazy;
        segmentTree[st<<1|1].lazy+=segmentTree[st].lazy;
        segmentTree[st].lazy=0;
    }
}
void UpDate1(int st,int l,int r,int value){
    //进行区间修改。
    if(segmentTree[st].l==l&&segmentTree[st].r==r){
        segmentTree[st].valueInfo = 0;
        segmentTree[st].lazy = value;//记录lazy标记。
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
void solve(){
}
int main(){	
    scanf("%d%d", &n, &m);
    BuildTree(1, 1, n);
    solve();
    return 0;
}