/**
  *@filename:D_Inconvenient_Pairs
  *@author: pursuit
  *@created: 2021-09-09 11:13
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//如果一个人从另一个仅仅通过街道的最短路径严格大于它们的曼哈顿距离，那么这一对人就形成了不方便的人。
//计算不方便人的个数。
int t, n, m, k;//n条垂直和m条水平的线。k个点。
int x[N], y[N];
void solve(){
    int xx, yy;
    map<int, int> px, py;
    map<pii, int> pxy, pyx;
    ll res = 0;
    while(k -- ){
        scanf("%d%d", &xx, &yy);
        int tx = lower_bound(x + 1, x + n + 1, xx) - x;
        int ty = lower_bound(y + 1, y + m + 1, yy) - y;
        if(x[tx] == xx && y[ty] == yy){
            //说明落在横线和纵线上。这个时候到达任何点都是曼哈顿距离。
            continue;
        } 
        else if(x[tx] == xx){
            //落在纵线上。那么此时的横线ty一定是大于yy的。
            res += py[ty] - pxy[pii(tx, ty)];
            ++ py[ty];
            ++ pxy[pii(tx, ty)];
        }
        else{
            //落在横线上，那么此时的纵线tx一定是大于xx的。
            res += px[tx] - pyx[pii(ty, tx)];
            ++ px[tx];
            ++ pyx[pii(ty, tx)];
        }
    }
    printf("%lld\n", res);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &x[i]);
        }
        for(int i = 1; i <= m; ++ i){
            scanf("%d", &y[i]);
        }
        solve();
    }
    return 0;
}