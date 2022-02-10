/**
  *@filename:K
  *@author: pursuit
  *@created: 2021-09-22 20:18
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

vector<int> g[N];
int t, n, m;
int u, v, cnt;
void solve(){
    while(m -- ){
        scanf("%d%d", &u, &cnt);
        bool flag = false;
        for(int i = 1; i <= cnt; ++ i){
            scanf("%d", &v);
            if(v > g[u].size()){
                flag = true;
            }
            if(flag)continue;
            u = g[u][v - 1];
        }
        if(flag)puts("Packet Loss");
        else{
            printf("%d\n", u);
        }
    }
    for(int i = 1; i <= n; ++ i){
        g[i].clear();
    }
}
int main(){	
    scanf("%d", &t);
    for(int k = 1; k <= t; ++ k){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &cnt);
            while(cnt -- ){
                scanf("%d", &v);
                g[i].push_back(v);
            }
        }
        printf("Case #%d: \n", k);
        solve();
    }
    return 0;
}