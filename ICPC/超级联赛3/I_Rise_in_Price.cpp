/**
  *@filename:I Rise in Price
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-27 12:08
**/
#include <bits/stdc++.h>
#define a first 
#define b second
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 100 + 5;
const int P = 1e9+7;

int t,n,a[N][N],b[N][N];
int cnt;//(i,j)可选状态的大小。
vector<pii> f[N][N];//f[i][j]表示(i,j)的可选状态。
pii pool[N * 10000];//可选状态池。
void push(pii x){
    while(cnt && pool[cnt].b <= x.b){
        cnt --;
    }
    pool[++ cnt] = x;//加入新的数。
}
void judge(int x,int y){
    int i = 0, j = 0;
    cnt = 0;
    //这里我们默认让a小的先进入pool。然后比较第二维的，若先前进入pool的b也比别的状态小，那就剔除掉。
    while(i < f[x - 1][y].size() && j < f[x][y - 1].size()){
        push(f[x - 1][y][i].a < f[x][y - 1][j].a ? f[x - 1][y][i ++ ] : f[x][y - 1][j ++ ]);
    }
    while(i < f[x - 1][y].size())push(f[x - 1][y][i ++]);
    while(j < f[x][y - 1].size())push(f[x][y - 1][j ++]);
    f[x][y].clear();
    //cout << "judge : " << endl;
    for(i = 1; i <= cnt; ++ i){
        f[x][y].push_back(pool[i]);
        //cout << pool[i].a << " " << pool[i].b << endl;
    }
}
void solve(){
    f[1][1].clear();
    f[1][1].push_back({a[1][1],b[1][1]});
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            if(i == j && i == 1)continue;
            if(i == 1){
                //说明只能水平转移。
                f[i][j] = f[i][j - 1];
            }
            else if(j == 1){
                //说明只能垂直转移。
                f[i][j] = f[i - 1][j];
            }
            else{
                //计算可选状态。
                judge(i,j);
            }
            for(int k = 0; k < f[i][j].size(); ++ k){
                f[i][j][k].a += a[i][j],f[i][j][k].b += b[i][j];
            }
        }
    }
    ll maxx = 0;
    for(int i = 0; i < f[n][n].size(); ++ i){
        maxx = max(maxx,1LL * f[n][n][i].a * f[n][n][i].b);
        //cout << maxx << endl;
    }
    printf("%lld\n", maxx);
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= n; ++ j){
                scanf("%d", &a[i][j]);
            }
        }
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= n; ++ j){
                scanf("%d", &b[i][j]);
            }
        }
        solve();
    }
    return 0;
}