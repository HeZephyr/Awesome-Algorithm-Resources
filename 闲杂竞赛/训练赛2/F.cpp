/**
  *@filename:F
  *@author: pursuit
  *@created: 2021-08-11 19:40
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m,r[N],pos[N],ans[N];
vector<int> g[N];
bool cmp(int i,int j){
    return r[i] < r[j];
}
void solve(){
    sort(pos + 1,pos + 1 + n,cmp);
    for(int i = 1; i <= n; ++ i){
        sort(g[i].begin(),g[i].end(),cmp);
    }
    for(int i = 1; i <= n; ++ i){
        int u = pos[i],w = r[pos[i]];//寻找
        int L = 1,R = n;
        while(L < R){
            int mid = (L + R) >> 1;
            if(r[pos[mid]] < w){
                L = mid + 1;
            }
            else{
                R = mid;
            }
        }
        ans[u] = L - 1;
        if(g[u].size() != 0){
            //debug(u);
            int L = 0, R = g[u].size();
            while(L < R){
                int mid = (L + R) >> 1;
                if(mid == g[u].size()){
                    L = mid;
                    break;
                }
                int v = g[u][mid];
                //debug(v);
                if(r[v] < w){
                    L = mid + 1;
                }
                else{
                    R = mid;
                }
            }
            //cout << L << endl;
            ans[u] -= L;
        }
    }
    for(int i = 1; i <= n; ++ i){
        printf("%d ", ans[i]);
    }
    puts("");
}
int main(){	
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &r[i]);
        pos[i] = i;
    }
    int u,v;
    for(int i = 1; i <= m; ++ i){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    solve();
    return 0;
}