/**
  *@filename:D2_Mocha_and_Diana_Hard_Version_
  *@author: pursuit
  *@created: 2021-08-16 10:57
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m[2],father[2][N];
int find(int op,int x){
    return father[op][x] ^ x ? father[op][x] = find(op,father[op][x]) : x;
}
void solve(){
    int res = 0;
    vector<pii> ans;
    int x,y,z,w;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            x = find(0,i),y = find(0,j),z = find(1,i),w = find(1,j);
            if((x ^ y) && (z ^ w)){
                father[0][x] = y;
                father[1][z] = w;
                res ++;
                ans.push_back({i,j});
            }
        }
    }
    printf("%d\n", res);
    for(int i = 0; i < res; ++ i){
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
}
int main(){	
    scanf("%d%d%d", &n, &m[0], &m[1]);
    for(int i = 1; i <= n; ++ i){
        father[0][i] = father[1][i] = i;
    }
    int u,v,fu,fv;
    for(int i = 1; i <= m[0]; ++ i){
        scanf("%d%d", &u, &v);
        fu = find(0,u),fv = find(0,v);
        if(fu ^ fv){
            father[0][fu] = father[0][fv];
        }
    }
    for(int i = 1; i <= m[1]; ++ i){
        scanf("%d%d", &u, &v);
        fu = find(1,u),fv = find(1,v);
        if(fu ^ fv){
            father[1][fu] = father[1][fv];
        }
    }
    solve();
    return 0;
}