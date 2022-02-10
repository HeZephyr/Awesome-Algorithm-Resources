/**
  *@filename:F
  *@author: pursuit
  *@created: 2021-09-28 15:07
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 5e2 + 10, M = 5e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//有三种类型的机器人，分别是只能向下移动，只能向右移动，既可以向下也可以向右移动的机器人。机器人需要从起始位置运送到目标位置。
//每个机器人都有一个类型，起始位置和目标位置，需要你判断机器人是否可以完成额包裹运送。
//给出的地图1表示不可达位置，0代表可达。
int n, m, q;
char s[N][N];
bitset<N * N> p[2][N];//p[0][j]表示这一行的j点能到达地图上的点的情况。 
vector<pii> v[N][N];//第一个参数代表结点位置，第二个代表查询的id。
int res[M];//为0代表无法到达。
void solve(){
    int op = 0;
    for(int i = n - 1; i >= 0; -- i){
        op ^= 1;
        for(int j = m - 1; j >= 0; -- j){
            if(s[i][j] == '0'){
                //说明该点可以到达，则其可以延伸i + 1,j和i, j + 1的状态。
                p[op][j] = p[op][j + 1] | p[op ^ 1][j];
                p[op][j].set(i * m + j);
            }
            else{
                p[op][j].reset();
            }
            //处理完之后，说明(i,j)能到达的点已经确定了。
            for(auto [x, id] : v[i][j]){
                res[id] = p[op][j][x];
            }
        }
    }
    for(int i = 1; i <= q; ++ i){
        if(res[i])puts("yes");
        else puts("no");
    }
}
int main(){	
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++ i){
        scanf("%s", s[i]);
    }
    scanf("%d", &q);
    for(int i = 1, t, x1, y1, x2, y2; i <= q; ++ i){
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
        if(t == 1 && y1 != y2)continue;
        if(t == 2 && x1 != x2)continue;
        v[x1 - 1][y1 - 1].push_back({(x2 - 1) * m + y2 - 1, i});
    }
    solve();
    return 0;
}