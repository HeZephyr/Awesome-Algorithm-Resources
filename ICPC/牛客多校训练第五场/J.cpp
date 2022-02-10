/**
  *@filename:J
  *@author: pursuit
  *@created: 2021-08-06 14:54
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 300 + 10;
const int P = 1e9 + 7;
const ll INF = 1e16;

ll g[N][N],lx[N],ly[N];//二部图，x部是宝石，y部是时刻,其中lx和ly分别为x和y的顶标。
int n,linker[N];//linker数组表示y部的配对状态。
bool visX[N],visY[N];//访问标记，是否在交错树上。
ll slack[N];
int last[N];//上一个点。
void bfs(int x){
    //x部的点。
    int y = 0,y1;//y记录交错树中最后加入的Y点。y1直接记录最小值对应的y点。
    for(int i = 1; i <= n; ++ i){
        last[i] = 0,slack[i] = INF;
    }
    linker[y] = x;
    do{
        int i = linker[y];
        ll d = INF;
        visY[y] = true;
        for(int j = 1; j <= n; ++ j){
            if(!visY[j]){
                //不在交错树上的Y点。
                if(slack[j] > lx[i] + ly[j] - g[i][j]){
                    slack[j] = lx[i] + ly[j] - g[i][j];
                    last[j] = y;//y是最新加入交错树中的点。
                }
                if(slack[j] < d){
                    d = slack[j];
                    y1 = j;
                }
            }
        }
        for(int j = 0; j <= n; ++ j){
            if(visY[j]){
                //交错树上的点。
                lx[linker[j]] -= d,ly[j] += d;
            }
            else{
                slack[j] -= d;
            }
        }
        y = y1;//更新y。
    }while(linker[y]);//如果y没有匹配则找到了增广路。
    while(y) linker[y] = linker[last[y]],y = last[y];//增广路取反。
}
ll KM(){
    for(int i = 0; i <= n; ++ i){
        linker[i] = lx[i] = ly[i] = 0;
    }
    for(int i = 1; i <= n; ++ i){
        //对每个点求一次匹配。
        for(int j = 0; j <= n; ++ j)visY[j] = false;//重新建立增广路。
        bfs(i);
    }
    ll ans = 0;
    for(int j = 1; j <= n; ++ j){
        if(linker[j])ans += g[linker[j]][j];
    }
    return ans;
}
void solve(){
    printf("%lld\n", -KM());
}
int main(){	
    scanf("%d", &n);
    int x,y,z,v;
    for(int i = 1; i <= n; ++ i){
        //i代表宝石
        scanf("%d%d%d%d", &x, &y, &z, &v);
        for(int j = 0; j < n; ++ j){
            //y代表时刻。
            g[i][j + 1] = -(x * x + y * y + 1LL * (z + j * v) * (z + j * v));
        }
    }
    solve();
    return 0;
}