/**
  *@filename:J_Road_DIscount
  *@author: pursuit
  *@created: 2021-07-27 13:20
**/
#include <bits/stdc++.h>
#define debug(a) cout << (#a)<< ":" << a << endl;
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,n,m;
int father[1010 * 2 + 10];
struct node{
    int u,v,w;
    int tag;//0表示正常价，1表示折扣价。
    bool operator < (const node &A){
        return w < A.w;
    }
}edges[N],edges1[N],edges2[N];
pii f[N];//第一维表示适用黑边的次数，第二维表示最小代价。
int find(int x){
    int r = x;
    while(r != father[r])r = father[r];
    int i = x,j;
    while(father[i] != r){
        j = father[i];
        father[i] = r;
        i = j;
    }
    return r;
}
void work(node *edges){
    for(int i = 1; i <= n; ++ i)father[i] = i;
    int tot = 0;
    for(int i = 1; i <= m; ++ i){
        int fu = find(edges[i].u),fv = find(edges[i].v);
        if(fu != fv){
            father[fu] = fv;
            edges[++ tot] = edges[i];
        }
    }
}
pii cal(int x){
    int cnt = 0,ans = 0,tot = 0;
    for(int i = 1; i <= m; ++ i){
        edges2[i].w += x;
    }
    edges1[m + 1].w = edges2[m + 1].w = 1e8;
    for(int i = 1; i <= n; ++ i)father[i] = i;
    for(int i = 1, j = 1; i <= m || j <= m;){
        if(edges1[i].w < edges2[j].w){
            edges[++ tot] = edges1[i ++];
        }
        else{
            edges[++ tot] = edges2[j ++];
        }
    }
    for(int i = 1; i <= tot; ++ i){
        int fu = find(edges[i].u),fv = find(edges[i].v);
        if(fu != fv){
            father[fu] = fv;
            cnt += edges[i].tag;
            ans += edges[i].w;
        }
    }
    for(int i = 1; i <= m; ++ i){
        edges2[i].w -= x;
    }
    return {cnt,ans};
}
void solve(){
    sort(edges1 + 1,edges1 + 1 + m);
    sort(edges2 + 1, edges2 + 1 + m);
    work(edges1),work(edges2);
    //处理完之后提取出我们要的n - 1条边。
    m = n - 1;
    //让黑边加上一个值。
    for(int i = -1010; i <= 1010; ++ i){
        f[1010 + i] = cal(i);
    }
    for(int k = 0; k < n; ++ k){
        int l = -1010, r = 1010,res,mid;
        while(l <= r){
            mid = l + r >> 1;
            if(f[mid + 1010].first >= k){
                //说明使用黑边数量多
                res = f[mid + 1010].second - mid * k;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        printf("%d\n", res);
    }
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; ++ i){
            scanf("%d%d%d%d", &edges1[i].u, &edges1[i].v, &edges1[i].w, &edges2[i].w);
            edges2[i].u = edges1[i].u,edges2[i].v = edges1[i].v;
            edges1[i].tag = 0,edges2[i].tag = 1;
        }
        solve();
    }
    return 0;
}