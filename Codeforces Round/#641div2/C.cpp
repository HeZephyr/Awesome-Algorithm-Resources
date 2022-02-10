/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-09-02 11:05
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, a[N], primer[N], tot; 
bool vis[N];
/* 
构造出多重集t，再求gcd。
 */
vector<int> g[N];
void init(){
    vis[1] = true;
    for(int i = 2; i < N; ++ i){
        if(!vis[i]){
            primer[++ tot] = i;
        }
        for(int j = 1; j <= tot && i * primer[j] < N; ++ j){
            vis[i * primer[j]] = true;
            if(i % primer[j] == 0)break;
        }
    }
}
void update(int x){
    for(int i = 1; i <= tot; ++ i){
        if(primer[i] * primer[i] > x)break;
        if(x % primer[i] == 0){
            int cnt = 0;
            while(x % primer[i] == 0){
                ++ cnt;
                x /= primer[i];
            }
            g[primer[i]].push_back(cnt);
        }
    }
    if(x > 1){
        g[x].push_back(1);
    }
}
void solve(){
    ll ans = 1;
    for(int i = 1; i <= tot; ++ i){
        int x = primer[i];
        sort(g[x].begin(), g[x].end());
        if(g[x].size() == n){
            //说明存在n个质因子。即每个都有。那么它们的lcm所作出的gcd一定是第二大的那个。因为会组合。
            for(int i = 1; i <= g[x][1]; ++ i){
                ans *= x;
            }
        }
        else if(g[x].size() == n - 1){
            //此时有一个不存在，这个不存在的和其他组合那么最小的那个贡献。
            for(int i = 1; i <= g[x][0]; ++ i){
                ans *= x;
            }
        }
        //当存在超过两个的时候，这两个的lcm不会有该因子。
    }
    printf("%lld\n", ans);
}
int main(){	
    scanf("%d", &n);
    init();
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        update(a[i]);
    }
    solve();
    return 0;
}