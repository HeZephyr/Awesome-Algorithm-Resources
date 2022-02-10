#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 500 + 10;
struct node{
    int x, y;
    ll w;
};
vector<node> g[10010];
int id[10010], hei[N];
int n, m, h[N][N], pos[10010];
ll res[N][N];
int tot;
int go[4][2] = {1, 0 , 0, 1, -1, 0, 0, -1};
bool cmp(int i, int j){
    return hei[i] > hei[j];
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            scanf("%d", &h[i][j]);
            if(!id[h[i][j]])id[h[i][j]] = ++ tot, hei[tot] = h[i][j];
            g[id[h[i][j]]].push_back({i, j, m});
        }
    }
    for(int i = 1; i <= tot; ++ i)pos[i] = i;
    sort(pos + 1, pos + 1 + tot, cmp);
    int x, y, w, dx, dy;
    for(int i = 1; i <= tot; ++ i){
        for(auto u : g[pos[i]]){
            x = u.x, y = u.y, w = u.w;
            for(int k = 0; k < 4; ++ k){
                dx = x + go[k][0], dy = y + go[k][1];
                //cout << dx << " " << dy << endl;
                if(dx >= 1 && dx <= n && dy >= 1 && dy <= n && h[dx][dy] < h[x][y]){
                    //可以转义过去。
                    //cout << dx << " " << dy << endl;
                    for(auto &v : g[id[h[dx][dy]]]){
                        if(v.x == dx && v.y == dy){
                            v.w += w;
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
    for(auto u : g[pos[tot]]){
        res[u.x][u.y] = u.w;
    }
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            printf("%lld", res[i][j]);
            if(res[i][j])printf(".000000");
            printf(" ");
        }
        puts("");
    }
}