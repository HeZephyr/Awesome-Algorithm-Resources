/**
  *@filename:Kanade_Loves_Maze_Designing
  *@author: pursuit
  *@created: 2021-08-04 14:13
**/
#include <bits/stdc++.h>
#define debug(a) cout << (#a)<< ":" << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e3 + 10;
const int X = 19560929;
const int P1 = 1e9 + 7;
const int P2 = 1e9 + 9;
const int INF = 0x3f3f3f3f;

int t,n;
int f1[N],f2[N];
int c[N],cnt[N],p[N];//点权,出现次数，p(i,j)。
int ans;
vector<int> g[N];//边权图
void init(){
    f1[1] = f2[1] = 1;
    for(int i = 2; i < N; ++ i){
        f1[i] = 1LL * f1[i - 1] * X % P1;
        f2[i] = 1LL * f2[i - 1] * X % P2;
    }
}
void dfs(int u,int fu){
    if(!cnt[c[u]]){
        ans ++;
    }
    cnt[c[u]] ++;
    p[u] = ans;
    for(auto &v : g[u]){
        if(v != fu){
            dfs(v,u);
        }
    }
    if(cnt[c[u]] == 1){
        ans --;
    }
    cnt[c[u]] --;
}
void solve(){
    for(int i = 1; i <= n; ++ i){
        ans = 0;
        dfs(i,-1);
        int h1 = 0,h2 = 0;
        for(int j = 1; j <= n; ++ j){
            h1 = (h1 + 1LL * f1[j] * p[j]) % P1;
            h2 = (h2 + 1LL * f2[j] * p[j]) % P2;
        }
        printf("%d %d\n", h1, h2);
    }
    for(int i = 1; i <= n; ++ i){
        g[i].clear();
    }
}
int main(){	
    scanf("%d", &t);
    init();
    while(t -- ){
        scanf("%d", &n);
        int x;
        for(int i = 2; i <= n; ++ i){
            scanf("%d", &x);
            g[x].push_back(i),g[i].push_back(x);
        }
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &c[i]);
        }
        solve();
    }
    return 0;
}