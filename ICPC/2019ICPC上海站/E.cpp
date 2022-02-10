#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 100;
const int maxn = N * N * 4 + 100;
int n, m, sx, sy, ex, ey;
int x[N * N + 100], a, b, c, p;
int w[N][N];
int f1[] = {1, 0, -1, 0};
int f2[] = {0, 1, 0, -1};
int fa[N * N + 100];
inline int find_fa(int x){return x == fa[x] ? fa[x] : fa[x] = find_fa(fa[x]);}
inline void add_fa(int x, int y){
    int u = find_fa(x);
    int v = find_fa(y);
    fa[v] = u;
}
struct p_node{
    int x, y, w;
};
bool operator < (p_node a, p_node b){
    return a.w < b.w;
}
int main(){
    int t;
    scanf("%d", &t);
    for(int k = 1; k <= t; ++ k){
        scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &ex, &ey);
        scanf("%d%d%d%d%d%d", &x[1], &x[2], &a, &b, &c, &p);
        for(int i = 0; i <= n * m; ++i)fa[i] = i;
        for(int i = 3; i <= n * m; ++ i){
            x[i] = (a * x[i - 1] + b * x[i - 2] + c) % p;
        }
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= m; ++ j){
                w[i][j] = x[(i - 1) * m + j];
               // cout << w[i][j] << " ";
            }
           // cout << endl;
        }
        priority_queue<p_node , vector<p_node>, less<p_node>> q;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                for(int k = 0; k < 4; ++k){
                    int x = i + f1[k], y = j + f2[k];
                    if(x < 1 || x > n || y < 1 || y > m)continue;
                    q.push({(i - 1) * m + j - 1, (x - 1) * m + y - 1, w[i][j] * w[x][y]});
                }
            }
        }
        long long  ans = 0;
        int sum = 0;
        while(q.size()){
            p_node u = q.top();
            q.pop();
            if(find_fa(u.x) == find_fa(u.y))continue;
            //cout << u.x << u.y << endl;
            add_fa(u.x, u.y);
            ans += u.w;
            //cout << ans << endl;
            sum++;
            if(sum == n * m - 1)break;
        }
        printf("Case #%d: ", k);
        printf("%lld\n", ans);
    }
    return 0;
}