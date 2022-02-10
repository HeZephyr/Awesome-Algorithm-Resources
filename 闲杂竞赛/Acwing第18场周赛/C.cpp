/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-09-26 18:42
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int cnt[N];
struct edge{
    int to, next;
}edges[N << 1];
int n, u, v, head[N], tot;
void add(int u, int v){
    edges[++ tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void dfs(int u, int fu = -1){
    ++ cnt[u];
    for(int i = head[u], v; i; i = edges[i].next){
        v = edges[i].to;
        if(v == fu)continue;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
}
void solve(){
    if(n & 1){
        puts("-1"); 
        return;
    }
    int res = 0;
    dfs(1);
    for(int i = 2; i <= n; ++ i){
        //cout << cnt[i] << " ";
        if(cnt[i] != 0 && cnt[i] % 2 == 0)++ res;
    }
    //cout << endl;
    printf("%d\n", res);
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i < n; ++ i){
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
    solve();
    return 0;
}