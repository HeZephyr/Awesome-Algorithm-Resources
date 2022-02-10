//ac代码
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm> 
using namespace std;
#define MAXN 201

struct node{
    int l,r;//左右整点区间
    int c;//覆盖标记
    double cnt;//覆盖长度
    double lf,rf;//左右实数区间 
}tree[MAXN*4];

struct line{
    double lf,y,rf;
    int d;
}scan[MAXN];

double x[MAXN];

bool cmp(line l1,line l2){
    return l1.y<l2.y;
}

void build(int i,int s,int e){
    tree[i].l=s;
    tree[i].r=e;
    tree[i].lf=x[s];
    tree[i].rf=x[e];
    tree[i].c=tree[i].cnt=0;
    if (s+1==e) return;
    int mid = (s+e)>>1;
    build(i<<1,s,mid);
    build(i<<1|1,mid,e);
}

void calen(int i){
    if (tree[i].c>0){
        tree[i].cnt=tree[i].rf-tree[i].lf;  //cout<<i<<" "<<tree[i].lf<<" "<<tree[i].rf<<" "<<tree[i].cnt<<"#"<<endl;
        return;
    }
    if (tree[i].r-tree[i].l==1) tree[i].cnt=0;
    else tree[i].cnt=tree[i<<1].cnt+tree[i<<1|1].cnt;
}

void updata(int i,line l){
    if (tree[i].lf>=l.lf&&tree[i].rf<=l.rf){
        tree[i].c+=l.d;
        calen(i);
        return;
    }
    if (tree[i].lf>=l.rf||tree[i].rf<=l.lf) return;
    updata(i<<1,l);
    updata(i<<1|1,l);
    calen(i);
}

int main()
{
    int n,i,j,icase=0;
    double x1,y1,x2,y2;
    while(~scanf("%d",&n)){
        if (n==0) break;
        icase++;
        for (i=0;i<n;++i){
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            scan[2*i].lf=x1;
            scan[2*i].rf=x2;
            scan[2*i].y=y1;
            scan[2*i].d=1;
            scan[2*i+1].lf=x1;
            scan[2*i+1].rf=x2;
            scan[2*i+1].y=y2;
            scan[2*i+1].d=-1;
            x[2*i]=x1;
            x[2*i+1]=x2;
        }
        sort(x,x+2*n);
        sort(scan,scan+2*n,cmp);
        //for (i=0;i<2*n;++i) cout<<x[i]<<" "<<scan[i].y<<" ";
        //cout<<endl;
        build(1,0,2*n-1);
        updata(1,scan[0]);
        double res=0;
        //cout<<scan[0].lf<<" "<<scan[0].rf<<endl; 
        //for (i=1;i<=7;++i) cout<<tree[i].c<<" "<<tree[i].cnt<<" "<<tree[i].lf<<" "<<tree[i].rf<<endl;
        //cout<<"$"<<endl;
        for (i=1;i<2*n;++i){
            res+=(scan[i].y-scan[i-1].y)*tree[1].cnt;
            updata(1,scan[i]);
            //cout<<scan[i].lf<<" "<<scan[i].rf<<endl;
            //for (int k=1;k<=7;++k) cout<<tree[k].c<<" "<<tree[k].cnt<<endl;
            //cout<<"$"<<endl;
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n",icase,res);
    }
}