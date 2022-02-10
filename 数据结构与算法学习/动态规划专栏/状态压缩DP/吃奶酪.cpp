/**
  *@filename:吃奶酪
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-30 14:20
**/
#include <bits/stdc++.h>
#define x first 
#define y second
using namespace std;

typedef long long ll;
typedef pair<double,double> pdd;
const int N = 16;
const int P = 1e9+7;

int n;
pdd a[N];
double dist[N][N];//dist[i][j]表示第i个奶酪到第j个奶酪的距离。
int g[1 << N];//奶酪的状态。
double f[1 << N][N];//f[i][j]表示当前为i状态，且处于第j个奶酪的最小距离。
pdd st;
double get(pdd a,pdd b){
    return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));
}
void solve(){
    //先计算距离。
    st.x = 0,st.y = 0;
    for(int i = 1; i <= n; ++ i){
        dist[0][i] = get(st,a[i]);
    }
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            dist[i][j] = get(a[i],a[j]);
        }
    }
     int maxn = 1 << n;
    //初始化奶酪的状态。
    g[1] = 1;
    for(int i = 2; i <= n; ++ i){
        g[i] = g[i - 1] << 1;
    }
    //初始化最大值。
    fill(f[0],f[0] + (1 << N) * N,0x3f3f3f3f);
    //确定只吃了一个奶酪的距离。
    for(int i = 1; i <= n; ++ i){
        f[g[i]][i] = dist[0][i];
    }
    f[0][0] = 0;//最开始自然为0，0.
    for(int i = 0; i < maxn ; ++ i){
        //枚举所有状态。
        for(int j = 1; j <= n; ++ j){
            if(i & g[j]){
                //该状态如果不包含此奶酪就跳过。
                for(int k = 1; k <= n; ++ k){
                    if(k != j && i & g[k]){
                        //说明符合条件。
                        f[i][j] = min(f[i][j],f[i - g[j]][k] + dist[k][j]);//进行状态转移。
                    }
                }
            }
        }
    }
    double maxx = 0x3f3f3f3f;
    for(int i = 1; i <= n; ++ i){
        maxx = min(maxx,f[maxn - 1][i]);
    }
    printf("%.2lf\n",maxx);
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%lf%lf", &a[i].x, &a[i].y);
    }
    solve();
    return 0;
}