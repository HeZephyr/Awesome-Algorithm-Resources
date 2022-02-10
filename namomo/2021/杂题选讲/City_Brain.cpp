/**
  *@filename:City_Brain
  *@author: pursuit
  *@created: 2021-10-26 13:54
**/
#pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 5e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//给出n个点m条边的无向带权图，初始边权都为1，一共有k次操作，每次操作可以选择一条边使其边权+1，通过一条边的时间为1 / 边权值，求min(dist(s1, t1) + dist(s2, t2))。
/*
两条路径的公共部分一定是连续的一段。则我们可以枚举公共部分的起点和终点，这样我们可以知道公共部分的长度和个人部分的长度。
*/

int n, m, k;
int s1, t1, s2, t2;
struct edge{
    int to, next;
}edges[N << 1];
int tot, head[N];
int dp[N];//dp[i]表示公共部分长度为i的两个人的最短个人部分的长度总和。
int dist[N][N];//dist[i][j]表示i到j的最短路径长度。
void add(int u, int v){
    edges[++ tot].to = v;
    edges[tot].next = head[u];
    head[u] = tot;
}
void bfs(int rt){
    //求最短路。
    queue<int> q;
    q.push(rt);
    dist[rt][rt] = 0;
    int u, v;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int i = head[u]; i; i = edges[i].next){
            v = edges[i].to;
            if(dist[rt][v] == INF){
                dist[rt][v] = dist[rt][u] + 1;
                q.push(v);
            }
        }
    }
}
bool check(int s, int i, int j, int t){
    if(dist[s][i] == INF || dist[i][j] == INF || dist[j][t] == INF){
        return false;
    }
    return true;
}
double getCost(int d, int k){
    //给每条边均分x次操作，其余操作给y条边，也就是说y条边获得x + 1次操作，其余边获得x次操作。
    int x = k / d, y = k % d;
    return 1.0 * y / (x + 2) + 1.0 * (d - y) / (x + 1);
}
double cal(int d1, int d2){
    //d1为个人部分长度的总和，d2为公共部分的长度。 
    //总共有k次操作，我们肯定要分给d1和d2，那么在分配上实际上就是一个凹函数，所以我们需要三分寻找极值点。
    //如果得到d1需要操作多少次，那么我们肯定是均分在这些边上。故花费可得。
   if(!d1 && !d2)return 0;
   else if(!d1){
       //说明只有公共部分。
       return 2 * getCost(d2, k);
   }
   else if(!d2){
       return getCost(d1, k);
   }
   else{
       int l = 0, r = k;
       double ans = 1e9;
       while(l <= r){
           int mid1 = l + (r - l) / 3;
           int mid2 = r - (r - l) / 3;
           double c1 = getCost(d1, mid1) + 2 * getCost(d2, k - mid1);
           double c2 = getCost(d1, mid2) + 2 * getCost(d2, k - mid2);
           if(c1 < c2){
               r = mid2 - 1;
               ans = c1;
           }
           else{
               l = mid1 + 1;
               ans = c2;
           }
       }
       return ans;
   }
} 
void solve(){
    for(int i = 1; i <= n; ++ i){
        dp[i] = INF;
        for(int j = 1; j <= n; ++ j){
            dist[i][j] = INF;
        }
    }
    for(int i = 1; i <= n; ++ i){
        bfs(i);
    }
    dp[0] = dist[s1][t1] + dist[s2][t2];
    for(int i = 1; i <= n; ++ i){
        //枚举公共部分的起点和终点。
        for(int j = 1; j <= n; ++ j){
            if((check(s1, i, j, t1) || check(s1, j, i, t1)) && (check(s2, i, j, t2) || check(s2, j, i, t2))){
                int d = dist[i][j];//公共边的长度。
                dp[d] = min(dp[d], min(dist[s1][i] + dist[j][t1], dist[s1][j] + dist[i][t1]) + 
                min(dist[s2][i] + dist[j][t2], dist[s2][j] + dist[i][t2]));
            }
        }
    }
    double res = INF;
    for(int i = 0; i < n; ++ i){
        if(dp[i] != INF){
            res = min(res, cal(dp[i], i));
        }
    }
    printf("%.10lf\n", res);
}
int main(){	
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0, u, v; i < m; ++ i){
        scanf("%d%d", &u, &v);
        add(u, v), add(v, u);
    }
    scanf("%d%d%d%d", &s1, &t1, &s2, &t2);
    solve();
    return 0;
}