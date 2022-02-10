/**
  *@filename:City
  *@author: pursuit
  *@created: 2021-09-04 18:21
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

struct edge{
    int u, v, w;
    bool operator < (const edge &A){
        return w > A.w;
    }
}edges[N];
int t, n, m, k, tot;
int p[N], pos[N], father[N];
ll cnt[N], res[N];
bool cmp(int i, int j){
    return p[i] > p[j];
}
int find(int x){
    int r = x;
    while(father[r] != r)r = father[r];
    int i = x, j;
    while(father[i] != r){
        j = father[i];
        father[i] = r;
        i = j;
    }
    return r;
}
void solve(){
    sort(pos + 1, pos + k + 1, cmp);
    sort(edges + 1, edges + tot + 1);
    //cout << cnt[1] << endl;
    for(int i = 1; i <= n; ++ i)father[i] = i, cnt[i] = 1;
    int x = 1;
    ll ans = 0;
    for(int i = 1; i <= k; ++ i){
        int idx = pos[i];
        //cout << p[idx] << endl;
        while(x <= tot && edges[x].w >= p[idx]){
            int fu = find(edges[x].u), fv = find(edges[x].v);
            //cout << edges[x].u << " " << edges[x].v << " " << edges[x].w << endl;
            if(fu != fv){
                ans += cnt[fu] * cnt[fv];
                //cout << cnt[fu] * cnt[fv] << endl;
                cnt[fv] += cnt[fu];
                father[fu] = fv;
            }
            ++ x;
        }
        res[idx] = ans;
        //cout << res[idx] << endl;
    }
    for(int i = 1; i <= k; ++ i){
        printf("%lld\n", res[i]);
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        tot = 0;
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= m; ++ i){
            ++ tot;
            scanf("%d%d%d", &edges[tot].u, &edges[tot].v, &edges[tot].w);
        }
        for(int i = 1; i <= k; ++ i){
            scanf("%d", &p[i]);
            res[i] = 0;
            pos[i] = i;
        }
        solve();
    }
    return 0;
}