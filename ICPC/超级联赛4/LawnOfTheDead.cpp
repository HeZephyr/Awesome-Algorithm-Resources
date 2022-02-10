/**
  *@filename:LawnOfTheDead
  *@author: pursuit
  *@created: 2021-08-04 14:48
**/
#include <bits/stdc++.h>
#define debug(a) cout << (#a)<< ":" << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

struct node{
    int l,r;
    int sum;//该区间中可以到达的区间点数。
    int flag;//初始化为-1，0表示不可到达，1表示可以到达。
}sTree[2][N << 4];
vector<int> g[N];
int t,n,m,k,x,y;//n * m grids,k个不可行的点。
void buildTree(int id,int rt,int l,int r){
    sTree[id][rt].l = l,sTree[id][rt].r = r;
    sTree[id][rt].sum = 0,sTree[id][rt].flag = -1;
    if(l == r){
        //说明到达叶子结点。
        return;
    }
    int mid = l + r >> 1;
    buildTree(id, rt << 1, l, mid);
    buildTree(id, rt << 1 | 1, mid + 1, r);
}
void pushdown(int id,int rt){
    if(sTree[id][rt].flag == -1){
        return;
    }
    sTree[id][rt << 1].sum = (sTree[id][rt << 1].r - sTree[id][rt << 1].l + 1) * sTree[id][rt].flag;
    sTree[id][rt << 1].flag = sTree[id][rt].flag;
    sTree[id][rt << 1 | 1].sum = (sTree[id][rt << 1 | 1].r - sTree[id][rt << 1 | 1].l + 1) * sTree[id][rt].flag;
    sTree[id][rt << 1 | 1].flag = sTree[id][rt].flag;
    //清除标记。
    sTree[id][rt].flag = -1;
}
void update(int id,int rt,int l,int r,int x){
    if(sTree[id][rt].l >= l && sTree[id][rt].r <= r){
        sTree[id][rt].sum = (sTree[id][rt].r - sTree[id][rt].l + 1) * x;
        sTree[id][rt].flag = x;
        return;
    }
    pushdown(id,rt);
    int mid = sTree[id][rt].l + sTree[id][rt].r >> 1;
    if(l <= mid){
        //说明在左子树。
        update(id,rt << 1,l,r,x);
    }
    if(r > mid){
        //说明在右子树。
        update(id,rt << 1 | 1,l,r,x);
    }
    sTree[id][rt].sum = sTree[id][rt << 1].sum + sTree[id][rt << 1 | 1].sum;
}
int query(int id,int rt,int l,int r){
    if(!sTree[id][rt].sum){
        //说明这段区间没有可走的点。
        return INF;
    }
    if(sTree[id][rt].l == sTree[id][rt].r){
        return sTree[id][rt].l;
    }
    pushdown(id,rt);
    //注意这里的细节，若左子树存在，右子树就可以不用去遍历了。
    if(sTree[id][rt].l >= l && sTree[id][rt].r <= r){
        if(sTree[id][rt << 1].sum > 0){
            //说明存在可选点。
            return query(id,rt << 1,l,r);
        }
        else{
            return query(id, rt << 1 | 1,l,r);
        }
    }
    int mid = sTree[id][rt].l + sTree[id][rt].r >> 1;
    int minn1 = INF,minn2 = INF;
    if(l <= mid){
        //说明在左子树。
        minn1 = query(id,rt << 1,l,r);
    }
    if(r > mid){
        //说明在右子树。
        minn2 = query(id, rt << 1 | 1,l,r);
    }
    return min(minn1,minn2);
}
void solve(){
    buildTree(0,1,1,m);
    buildTree(1,1,1,m);
    update(0,1,1,1,1);//设置第一行的第一个点能走。
    int l,r;
    ll ans = 0;
    for(int i = 1; i <= n; ++ i){
        g[i].push_back(0),g[i].push_back(m + 1);
        sort(g[i].begin(),g[i].end());
        for(int j = 0; j < g[i].size() - 1; ++ j){
            l = g[i][j], r = g[i][j + 1];
            if(l + 1 <= r - 1){
                //查询上一行这一段区间中早能到达的点。
                int minn = query((i & 1) ^ 1,1,l + 1,r - 1);
                if(minn != INF){
                    //说明存在可走的点。
                    update(i & 1,1,minn,r - 1,1);
                }
            }
        }
        ans += sTree[i & 1][1].sum;
        update((i & 1) ^ 1,1,1,m,0);//将其清空，供下次使用。
    }
    printf("%lld\n", ans);
    for(int i = 1; i <= n; ++ i){
        g[i].clear();
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d%d", &n, &m, &k);
        while(k -- ){
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
        }
        solve();
    }
    return 0;
}