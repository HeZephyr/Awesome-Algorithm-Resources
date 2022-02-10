/**
  *@filename:矩形面积并
  *@author: pursuit
  *@created: 2021-08-07 20:33
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

int n,k;
struct Line{
    double yd,yu,xx;//边的y上坐标y下坐标，横坐标。
    int d;//区分入边和出边。入边为1，出边为-1.
    bool operator < (const Line &A){
        return xx < A.xx;
    }
    Line(){}
    Line(double _yd,double _yu,double _xx,int _d):
    yd(_yd),yu(_yu),xx(_xx),d(_d){}
}scan[N];//扫描线。
int tot;//扫描线数量。
int cover[N];//存放i结点对应覆盖情况的值。
double length[N];//存放区间i下的总长度。
double yy[N];//存放离散后的y的值，下标我们用lower_bound进行查找。
void pushup(int rt,int l,int r){
    if(cover[rt]){
        length[rt] = yy[r] - yy[l];
    }
    else if(l + 1 == r){
        length[rt] = 0;//到了叶子结点。
    }
    else{
        length[rt] = length[rt << 1] + length[rt << 1 | 1];
    }
}
void update(int rt,int l,int r,int yl,int yr,int d){
    if(yl <= l && yr >= r){
        //说明区间全部包含在里面。
        cover[rt] += d;//根据出边入边加上相应值。
        pushup(rt,l,r);
        return;
    }
    if(l + 1 == r)return;//到了子节点。
    int mid = (l + r) >> 1;
    if(yl <= mid){
        update(rt << 1,l,mid,yl,yr,d);
    }
    if(yr > mid){
        update(rt << 1 | 1,mid,r,yl,yr,d);
    }
    pushup(rt,l,r);
} 
void solve(){
    sort(yy + 1,yy + tot + 1);//排序。
    sort(scan + 1,scan + 1 + tot);
    //获取去重后的数组。
    int len = unique(yy + 1,yy + tot + 1) - (yy + 1);
    fill(length,length + N,0);
    fill(cover,cover + N,0);
    int yl,yr;
    double ans = 0;//累加矩形面积。
    for(int i = 1; i <= tot; ++ i){
        ans += length[1] * (scan[i].xx - scan[i - 1].xx);
        yl = lower_bound(yy + 1,yy + 1 + len,scan[i].yd) - yy;
        yr = lower_bound(yy + 1,yy + 1 + len,scan[i].yu) - yy; 
        update(1,1,len,yl,yr,scan[i].d);
    }
    printf("Test case #%d\nTotal explored area: %.2f\n\n",k,ans);
}
int main(){	
    pdd a,b;
    while(~scanf("%d", &n) && n){
        k ++;
        tot = 0;
        for(int i = 0; i < n; ++ i){
            //矩形的左下角和右上角坐标。
            scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y);
            //下底扫描线和上底扫描线。
            //即给入边和出边赋值。
            scan[++tot] = Line(a.y,b.y,a.x,1);
            yy[tot] = a.y;
            scan[++tot] = Line(a.y,b.y,b.x,-1);
            yy[tot] = b.y;
        }
        solve();
    }
    return 0;
}