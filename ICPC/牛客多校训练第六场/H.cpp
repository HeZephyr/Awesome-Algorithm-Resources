/**
  *@filename:H
  *@author: pursuit
  *@created: 2021-08-07 13:48
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;
#define x first 
#define y second

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//用左下角(x_1,y_1)和右上角(x_2,y_2)来描述一个陷阱矩阵。
int n,d;//n个陷阱，d为跳跃的长度。
struct Line{
    int yl,yr;//左右端点。
    int d;//是入边还是出边。
    Line(){};
    Line(int yl,int yr,int d) : yl(yl),yr(yr),d(d){};
};
vector<Line> scan[N];//扫描线。scan[i]代表扫描线高度为i的集合。利用桶排序。
struct node{
    int l,r,minn,lazy;
}tree[N << 2];
void buildTree(int rt,int l,int r){
    //cout << rt << " " << l << " " << r << endl;
    tree[rt] = {l,r,0,0};
    if(l == r){
        return;//说明到了叶子结点。
    }
    int mid = l + r >> 1;
    buildTree(rt << 1,l,mid);
    buildTree(rt << 1 | 1,mid + 1,r);
}
void pushup(int rt){
    tree[rt].minn = min(tree[rt << 1].minn,tree[rt << 1 | 1].minn);
}
void pushdown(int rt){
    if(tree[rt].lazy){
        int &lz = tree[rt].lazy;
        tree[rt << 1].minn += lz;
        tree[rt << 1].lazy += lz;
        tree[rt << 1 | 1].minn += lz;
        tree[rt << 1 | 1].lazy += lz;
        lz = 0;
    }
}
void update(int rt,int l,int r,int d){
    if(l <= tree[rt].l && r >= tree[rt].r){
        //整个区间都被覆盖了。
        tree[rt].minn += d;
        tree[rt].lazy += d; 
        return;   
    }
    pushdown(rt);
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if(l <= mid){
        update(rt << 1,l,r,d);
    }
    if(r > mid){
        update(rt << 1 | 1,l,r,d);
    }
    pushup(rt);
}
int query(int rt,int l,int r){
    if(l <= tree[rt].l && r >= tree[rt].r){
        return tree[rt].minn;
    }
    pushdown(rt);
    int mid = tree[rt].l + tree[rt].r >> 1;
    int res = INF;
    if(l <= mid){
        res = min(res,query(rt << 1,l,r));
    }
    if(r > mid){
        res = min(res,query(rt << 1 | 1,l,r));
    }
    return res;
}
void mod(pii &a){
    a.x = (a.x % d + d) % d, a.y = (a.y % d + d) % d;
}
void add(int x1,int x2,int y1,int y2){
    //cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
    scan[x1].push_back(Line(y1,y2,1));//入边。
    scan[x2 + 1].push_back(Line(y1,y2,-1));//出边。
}
void push(pii a,pii b){
    if(a.x <= b.x){
        if(a.y <= b.y){
            //说明只能分成一个矩形。
            add(a.x,b.x,a.y,b.y);
        }
        else{
            add(a.x,b.x,a.y,d - 1),add(a.x,b.x,0,b.y);
        }
    }
    else{
        //a.x > b.x;
        if(a.y <= b.y){
            add(0,b.x,a.y,b.y),add(a.x,d - 1,a.y,b.y);
        }
        else{
            //a.y > b.y;
            add(0,b.x,a.y,d - 1),add(0,b.x,0,b.y);
            add(a.x,d - 1,a.y,d - 1),add(a.x,d - 1,0,b.y);
        }
    }
}
void solve(){
    pii ans = pii(-1,-1);
    buildTree(1,0,d - 1);
    for(int i = 0; i < d; ++ i){
        if(ans.x != - 1)break;
        for(auto &l : scan[i]){
            update(1,l.yl,l.yr,l.d);
        }
        if(query(1,0,d - 1) == 0){
            //判断是否存在没有被覆盖的位置。
            for(int j = 0; j < d; ++ j){
                if(query(1,j,j) == 0){
                    ans.x = i,ans.y = j;
                    break;
                }
            }
        }
    }
    if(ans.x != - 1){
        puts("YES");
        printf("%d %d\n", ans.x, ans.y);
    }
    else{
        puts("NO");
    }
}
int main(){
    scanf("%d%d", &n, &d);
    pii a,b;
    for(int i = 1; i <= n; ++ i){
        scanf("%d%d%d%d", &a.x, &a.y, &b.x, &b.y);
        b.x --,b.y --;
        if(b.x - a.x + 1 >= d){
            b.x = d - 1,a.x = 0;
        }
        if(b.y - a.y + 1 >= d){
            b.y = d - 1,a.y = 0;
        }
        mod(a),mod(b);
        push(a,b);
    }
    solve();
    return 0;
}