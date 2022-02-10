/**
  *@filename:H
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-20 13:02
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e3 + 5;
const int P = 1e9+7;

int t,n,m;
int g[N][N],h[N][N],q[N],w[N];
ll cal(int n){
    //第n行。
    int top = 0;
    ll ans = 0;
    h[n][m + 1] = 0;
    for(int j = 1; j <= m + 1; ++ j){
        if(h[n][j] > q[top]){
            q[++ top] = h[n][j],w[top] = 1;
        }
        else{
            int length = 0;
            while(q[top] > h[n][j]){
                length += w[top];
                ans = max(ans, 1LL * length * q[top]);
                top --;
            }
            q[++ top] = h[n][j];
            w[top] = length + 1;
        }
    }
    return ans;
}
void solve(){
    ll ans = 0;
    for(int i = 1; i <= n; ++ i){
        ans = max(ans, cal(i));
    }
    printf("%lld\n", ans);
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        memset(h,0,sizeof(h));
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= m; ++ j){
                scanf("%d", &g[i][j]);
                //记录其延伸到第i行的高度。
                if(g[i][j] >= g[i - 1][j]){
                    h[i][j] = h[i - 1][j] + 1;
                }
                else{
                    h[i][j] = 1;
                }
            }
        }
        solve();
    }
    return 0;
}