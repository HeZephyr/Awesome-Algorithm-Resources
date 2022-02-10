#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

struct node
{
    int l,r;
    int num[8];//存储[l,r]区间的八大奇迹。
}t[N<<2];
int n,m;
inline void push_up(int ta[],int la[],int ra[])
{
    sort(la ,la+8 );
    sort(ra ,ra+8 );
    int l = 7,r = 7,idx = 7;
    while(idx >=0){
        if(la[l] >= ra[r]){
            ta[idx--] = la[l--];
        }
        else  ta[idx--] = ra[r--];
        ///
        if( l == -1 && idx >= 0){
            while( idx < 8 && r >=0 ){
                ta[idx--] = la[l--];
            }
            break;
        }
        if( r == -1 && idx >=0 ){
            while(idx < 8 && l >= 0){
                ta[idx--] = ra[r--];
            }
            break;
        }
    }
    return ;
}

void build(int rt,int l, int r)
{
    t[rt].l = l , t[rt].r = r;
    if(l == r){
        for(int i = 0;  i < 8 ; i++){
            t[rt].num[i] = 0;
        }
        return ;
    }
    int mid = (l + r) >> 1;
    build(rt << 1,l,mid),build(rt <<1|1,mid+1,r);
}

inline void update(int rt,int loc,int val)
{
    if( t[rt].l == t[rt].r && t[rt].l == loc ){
        t[rt].num[7] = val;
        return ;
    }
    int mid = t[rt].l +t[rt].r >>1;
    if( loc <= mid ) update( rt << 1, loc ,val );
    else update( rt <<1|1,loc ,val );
    push_up(t[rt].num , t[rt<<1].num,t[rt<<1|1].num);
}

inline int* rangeQuery(int rt,int l,int r)
{
    //cout << rt << ' ' <<t[rt].l << ' ' << t[rt].r <<' '<< l <<' ' <<r <<endl;
    if( l <= t[rt].l && r >= t[rt].r ){
        return t[rt].num;
    }
    //if( t[rt].l >r ||t[rt].r < l ) return new int[8];
    int mid = t[rt].l +t[rt].r >> 1;
    if( r <= mid )  return rangeQuery(rt<<1 ,l ,r);
    if( l > mid )   return rangeQuery(rt<<1|1,l,r);
    int *la = rangeQuery(rt<<1,l,r);
    int *ra = rangeQuery(rt<<1|1,l,r);
    int *ta = new int[8];
    memset(ta,0,sizeof ta);
    push_up(ta,la,ra);
    return ta;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    build(1,1,n);
    for(int i = 0 ; i < m ; i++){
        char op;
        int x,y;
        cin >> op >> x >> y;
        if(op == 'C'){
            update(1,x,y);
        }
        else{
            //cout << "--" << x << ' ' << y <<endl;
            int *ans = rangeQuery(1,x,y);
            cout << ans[0] <<endl;
//            cout << "-------" <<endl;
//            for(int i = 0 ; i < 8 ; i ++){
//                cout << ans[i] << endl;
//            }
//            cout << "-------" <<endl;
        }

    }
    return 0;
}
/*
8 9
C 1 20
C 2 30
C 6 24
Q 1 2
C 3 23
C 4 43
C 5 90
C 7 53
C 8 12
*/