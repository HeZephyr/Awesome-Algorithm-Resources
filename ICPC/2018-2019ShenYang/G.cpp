#include<bits/stdc++.h>
/* #define x first
#define y second */
using namespace std;

typedef pair<int, int> pii;

const int N = 6010,M = 1e7 + 10;
long long a[N][N];
bool flag[10005];
int p1[10005 << 1],p2[10005 << 1],cnt;
vector<pii> f[M];
/* int get(pii a, pii b){
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
} */
void init(){
    for(int i = 0; i <= 6010; ++ i){
        for(int j = 0; j <= 6010; ++ j){
            if(i * i + j * j > 1e7)break;
            if(i == j){
                if(flag[i])continue;
                else flag[i] = true;
            }
            f[i * i + j * j].push_back({i,j});
        }
    }
}
int main() {
    int t;
    init();
    scanf("%d", &t);
    int n, m;
    long long last = 0;
    for (int Case = 1; Case <= t; ++ Case ) {
        scanf("%d%d", &n, &m);
        int x, y, op;
        long long w,k;
        cnt = 0;
        for (int i = 1; i <= n; ++ i) {
            scanf("%d%d%lld", &x, &y, &w);
            a[x][y] = w;
            p1[++ cnt] = x,p1[cnt] = y;
        }
        printf("Case #%d:\n", Case);
        while (m -- ) {
            scanf("%d%d%d", &op, &x, &y);
            x = (x + last) % 6000 + 1;
            y = (y + last) % 6000 + 1;
            if (op == 1) {
                scanf("%lld", &w);
                a[x][y] = w;
                p1[++ cnt] = x,p1[cnt] = y;
            } else if (op == 2) {
                a[x][y] = 0;
            }
            else if(op == 3){
                scanf("%lld%lld", &k, &w);
                for(int idx = 0; idx < f[k].size(); ++ idx){
                    int xx[3],yy[3];
                    xx[1] = f[k][idx].first + x,xx[2] = x - f[k][idx].first;
                    yy[1] = y + f[k][idx].second,yy[2] = x - f[k][idx].second;
                    for(int i = 1; i <= 2; ++ i){
                        if(xx[i] > 6000 || xx[i] < 1)continue;
                        if(i == 2 && xx[i] == xx[i - 1])continue;
                        for(int j = 1; j <= 2; ++ j){
                            if(yy[j] > 6000 || yy[j] < 1)continue;
                            if(j == 2 && yy[j] == yy[j - 1])continue;
                            if(a[xx[i]][yy[j]]){
                                a[xx[i]][yy[j]] += w;
                            }
                        }
                    }
                }
            } 
            else{
                scanf("%lld", &k);
                long long ans = 0;
                for(int idx = 0; idx < f[k].size(); ++ idx){
                    int xx[3],yy[3];
                    xx[1] = f[k][idx].first + x,xx[2] = x - f[k][idx].first;
                    yy[1] = y + f[k][idx].second,yy[2] = x - f[k][idx].second;
                    for(int i = 1; i <= 2; ++ i){
                        if(xx[i] > 6000 || xx[i] < 1)continue;
                        if(i == 2 && xx[i] == xx[i - 1])continue;
                        for(int j = 1; j <= 2; ++ j){
                            if(yy[j] > 6000 || yy[j] < 1)continue;
                            if(j == 2 && yy[j] == yy[j - 1])continue;
                            ans += a[xx[i]][yy[j]];
                        }
                    }
                }
                printf("%lld\n", ans);
                last = ans;
            }
        }
        for(int i = 1; i <= cnt; ++ i){
            a[p1[i]][p2[i]] = 0;
        }
    }
    return 0;
}