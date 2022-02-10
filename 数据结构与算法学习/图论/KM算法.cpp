/**
  *@filename:KM算法
  *@author: pursuit
  *@created: 2021-08-06 11:30
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 300 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int nx,ny;//两边x和y的点数。
bool visX[N],visY[N];//判断是否已经加入增广路。
int g[N][N];//二部图。
int linker[N],lx[N],ly[N];//linker数组表示y中的各点匹配状态，lx和ly分别代表x和y的顶标
int slack[N];//松弛函数，slack[j]保存的是当前结点j相连的结点i的min{lx[i] + ly[j] - weight(x,y)}。
bool dfs(int x){
    //进入的都是x部的顶点。
    visX[x] = true;
    for(int y = 1; y <= ny; ++ y){
        if(visY[y])continue;//判断是否在交错路中。
        int temp = lx[x] + ly[y] - g[x][y];
        if(temp == 0){
            //说明x和y的边在相关子图中。
            visY[y] = true;
            if(linker[y] == -1 || dfs(linker[y])){
                //这里利用匈牙利算法思想，能让就让的原则。
                linker[y] = x;
                return true;
            }
        }
        else if(slack[y] > temp){
            slack[y] = temp;//(x,y)不在相等子图中且y不在交错树中。
        }
    }
    return false;
}
ll KM(){
    memset(linker,-1,sizeof(linker));//初始化为-1，y部所有顶点暂未匹配。
    memset(ly,0,sizeof(ly));//即第二步。
    for(int i = 1; i <= nx; ++ i){
        lx[i] = -INF;
        for(int j = 1; j <= ny; ++ j){
            lx[i] = max(lx[i],g[i][j]);//获取边权最大值。
        }
    }
    for(int x = 1; x <= nx; ++ x){
        for(int y = 1; y <= ny; ++ y){
            slack[y] = INF;//每次换新的结点都需要初始化slack。
        }
        while(true){
            memset(visX,false,sizeof(visX));
            memset(visY,false,sizeof(visY));
            if(dfs(x))break;//说明匹配成功。
            int d = INF;
            //匹配失败，x一定在交错路中，而y不在。
            for(int y = 1; y <= ny; ++ y){
                //获取最小值。
                if(!visY[y] && d > slack[y]){
                    d = slack[y];
                }
            }
            for(int i = 1; i <= nx; ++ i){
                if(visX[i]){
                    lx[i] -= d;
                }
            }
            for(int y = 1; y <= ny; ++ y){
                //修改顶标后同时也要修改slack数组，这是因为lx[i]减小了d。而slack[j] = min(lx[i] + ly[j] - g[i][j])。
                if(visY[y]){
                    ly[y] += d;
                }
                else{
                    slack[y] -= d;
                }
            }
        }
    }
    ll ans = 0;
    for(int y = 1; y <= ny; ++ y){
        if(linker[y] != -1){
            ans += g[linker[y]][y];
        }
    }
    return ans;
}
void solve(){
}
int main(){	
    int n;//房子数量。
    while(~scanf("%d", &n)){
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= n; ++ j){
                scanf("%d", &g[i][j]);
            }
        }
        nx = n,ny = n;
        printf("%lld\n", KM());
        solve();
    }
    return 0;
}