/**
  *@filename:new_矩形面积并
  *@author: pursuit
  *@created: 2021-08-08 14:58
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;
#define x first
#define y second
using namespace std;

typedef pair<double,double> pdd;
typedef long long ll;
const int N = 4e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

struct Line{
    double xl,xr;//扫描线的左端和右端。
    double yy;//扫描线的高度。
    int d;//代表是入边还是出边，其中规定底边为入边，顶边为出边。
    bool operator < (const Line &A){
        return yy < A.yy;
    }
    Line(){}
    Line(double _xl,double _xr,double _yy,int _d):xl(_xl),xr(_xr),yy(_yy),d(_d){}
}scan[N];
int cover[N];//区间i的覆盖情况。
double length[N];//端点i的长度。
double xx[N];//存放离散化后的x值。
int n,k,tot;//n个矩形。tot根扫描线。
void pushup(int rt,int l,int r){
    //判断是否完全覆盖该区间。
    if(cover[rt]){
        //更新区间长度。
        length[rt] = xx[r] - xx[l];
    }
    else if(l + 1 == r){
        //由于cover[0] = 0,且为叶子结点。到了叶子结点不可能由子节点贡献覆盖了。
        length[rt] = 0;
    }
    else{
        length[rt] = length[rt << 1] + length[rt << 1 | 1];
    }
}
void update(int rt,int l,int r,int xl,int xr,int d){
    //判断是否完全覆盖了当前结点的区间
    if(xl <= l && xr >= r){
        //就更新这个区间。
        cover[rt] += d;//更新这个区间的覆盖情况。
        pushup(rt,l,r);
        return;
    }
    if(l + 1 == r)return;
    int mid = (l + r) >> 1;
    if(xl <= mid){
        update(rt << 1,l,mid,xl,xr,d);
    }
    if(xr > mid){
        update(rt << 1 | 1,mid,r,xl,xr,d);
    }
    pushup(rt,l,r);
}
void solve(){
    //对扫描线和x排序。
    sort(xx + 1,xx + tot + 1);
    sort(scan + 1,scan + tot + 1);
    //获取去重后的长度。同时也离散化了xx。
    int len = unique(xx + 1,xx + tot + 1) - (xx + 1);
    //初始化。
    fill(cover,cover + N,0);
    fill(length,length + N,0);
    int xl,xr;//获取离散化后的xl和xr。
    double ans = 0;
    for(int i = 1; i <= tot; ++ i){
        //相邻两根扫描线之间的高度差即是高。而length[1]代表的是根节点管辖的区间覆盖宽度，正是宽。
        ans += length[1] * (scan[i].yy - scan[i - 1].yy);
        //将这根扫描线加入到线段树中。
        //查找第一个大于等于查找值的元素，而由于去重了，且一定存在，所以即是其本身下标。
        xl = lower_bound(xx + 1,xx + len + 1,scan[i].xl) - xx;
        xr = lower_bound(xx + 1,xx + len + 1,scan[i].xr) - xx;
        update(1,1,len,xl,xr,scan[i].d);
    }
    printf("Test case #%d\nTotal explored area: %.2f\n\n",k,ans);
}
int main(){	
    k = 0;
    pdd a,b;
    while(~scanf("%d", &n) && n){
        k ++,tot = 0;
        for(int i = 1; i <= n; ++ i){
            scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y);
            scan[++tot] = Line(a.x,b.x,a.y,1);
            xx[tot] = a.x;
            scan[++tot] = Line(a.x,b.x,b.y,-1);
            xx[tot] = b.x;
        }
        solve();
    }
    return 0;
}