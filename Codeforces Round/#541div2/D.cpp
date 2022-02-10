/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-09-09 17:50
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m;
char s[N][N];
int father[N << 1];
int in[N << 1], res[N << 1];
vector<int> g[N << 1];
int q[N << 1], st, ed;
int find(int x){
    int r = x;
    while(father[r] != r)r = father[r];
    int i = x, j;
    while(father[i] != r){
        j = father[i], father[i] = r, i = j;
    }
    return r;
}
void solve(){
    //考虑如果a > b则a -> b否则a <- b;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            if(s[i][j] == '>'){
                //a > b;
                g[find(j + n)].push_back(find(i));
                ++ in[find(i)];
            }
            else if(s[i][j] == '<'){
                //a < b;
                g[find(i)].push_back(find(j + n));
                ++ in[find(j + n)];
            }
        }
    }
    //考虑利用topoSort。
    st = 1, ed = 0;
    for(int i = 1; i <= n + m; ++ i){
        if(!in[i]){
            q[++ ed] = i;
            res[i] = 1;
        }
    }
    while(st <= ed){
        int u = q[st ++];
        for(auto v : g[u]){
            res[v] = max(res[v], res[u] + 1);
            -- in[v];
            if(!in[v]){
                q[++ ed] = v;
            }
        }
    }
    for(int i = 1; i <= n + m; ++ i){
        if(in[i]){
            puts("No");
            return;
        }
    }
    puts("Yes");
    for(int i = 1; i <= n; ++ i){
        printf("%d ", res[find(i)]);
    }
    puts("");
    for(int i = n + 1; i <= n + m; ++ i){
        printf("%d ", res[find(i)]);
    }
    puts("");
}
int main(){	
    scanf("%d%d", &n ,&m);
    for(int i = 1; i <= n + m; ++ i){
        father[i] = i;
    }
    for(int i = 1; i <= n; ++ i){
        scanf("%s", s[i] + 1);
        for(int j = 1; j <= m; ++ j){
            //为等号的即是相同的，我们将其合并在一起。
            if(s[i][j] == '='){
                father[find(i)] = father[find(j + n)];
            }
        }
    }
    solve();
    return 0;
}