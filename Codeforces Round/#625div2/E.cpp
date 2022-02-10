/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-09-03 14:06
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m, p;//可用武器数，盔甲数以及怪物数量。
struct node1{
    int w, c;
    //按能力值排序。
    node1(int _w = 0){
        w = _w, c = 0;
    }
}a[N], b[N];
ll tree[N << 2], lazy[N << 2];
struct node2{
    int x, y, z;//防御攻击和金币数。
}monster[N];
bool operator < (node1 A, node1 B){
    return A.w < B.w;
}
bool operator < (node2 A, node2 B){
    return A.x < B.x;
}
void buildTree(int rt, int l, int r){
    if(l == r){
        tree[rt] = -b[l].c;//该结点的所需装备的值。
        return;
    }
    int mid = l + r >> 1;
    buildTree(rt << 1, l, mid);
    buildTree(rt << 1 | 1, mid + 1, r);
    tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
}
void pushdown(int rt){
    tree[rt << 1] += lazy[rt], tree[rt << 1 | 1] += lazy[rt];
    lazy[rt << 1] += lazy[rt], lazy[rt << 1 | 1] += lazy[rt];
    lazy[rt] = 0;
}
void update(int rt, int l, int r, int st, int ed, int x){
    if(st <= l && r <= ed){
        //说明范围包含了这个区间。
        tree[rt] += x, lazy[rt] += x;
        return;
    }
    //否则在子树里标记下移。
    pushdown(rt);
    int mid = l + r >> 1;
    if(st <= mid){
        update(rt << 1, l, mid, st, ed, x);
    }
    if(ed > mid){
        update(rt << 1 | 1, mid + 1, r, st, ed, x);
    } 
    tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
}
void solve(){
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    sort(monster + 1, monster + p + 1);
    ll res = -1e17;
    buildTree(1, 1, m);
    for(int i = 1, num = 1; i <= n; ++ i){
        //判断能大于多少的怪物防御。
        while(num <= p && monster[num].x < a[i].w){
            //此时二分出该怪物至少需要多少防御的盔甲才可以。
            int x = upper_bound(b + 1, b + 1 + m, node1(monster[num].y)) - b;
            //cout << x << " " << b[x].w << " " << b[x].c << endl;
            if(x <= m){
                //说明存在。则对这一部分的均进行修改。
                update(1, 1, m, x, m, monster[num].z);
            }
            ++ num;
        }
        res = max(res, tree[1] - a[i].c);
    }
    printf("%lld\n", res);
}
int main(){	
    scanf("%d%d%d", &n, &m, &p);
    for(int i = 1; i <= n; ++ i){
        scanf("%d%d", &a[i].w, &a[i].c);
    }
    for(int i = 1; i <= m; ++ i){
        scanf("%d%d", &b[i].w, &b[i].c);
    }
    for(int i = 1; i <= p; ++ i){
        scanf("%d%d%d", &monster[i].x, &monster[i].y, &monster[i].z);
    }
    solve();
    return 0;
}