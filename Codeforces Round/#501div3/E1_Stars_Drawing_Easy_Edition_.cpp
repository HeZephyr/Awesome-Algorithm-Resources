/**
  *@filename:E1_Stars_Drawing_Easy_Edition_
  *@author: pursuit
  *@created: 2021-10-26 20:07
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m, cnt[4], go[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
char s[N][N];
int res[N][N];
bool vis[N][N];
struct node{
    int i, j, k;
};
bool check(){
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            if(!vis[i][j] && s[i][j] == '*'){
                return true;
            }
        }
    }
    return false;
}
void solve(){
    int ans = 0;
    vector<node> res;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            if(s[i][j] == '*'){
                memset(cnt, 0, sizeof(cnt));
                for(int k = 0; k < 4; ++ k){
                    int x = i, y = j;
                    while(x >= 1 && x <= n && y >= 1 && y <= m){
                        x += go[k][0], y += go[k][1];
                        if(x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] == '*')++ cnt[k];
                        else break;
                    }
                }
                sort(cnt, cnt + 4);
                if(cnt[0] > 0){
                    res.push_back({i, j, cnt[0]});
                    vis[i][j] = true;
                    ++ ans;
                    for(int k = 0; k < 4; ++ k){
                        int x = i, y = j;
                        for(int j = 0; j < cnt[0]; ++ j){
                            x += go[k][0], y += go[k][1];
                            vis[x][y] = true;
                        }
                    }
                }
            }
        }
    }
    if(check()){
        puts("-1");
        return;
    }
    printf("%d\n", ans);
    for(int i = 0; i < ans; ++ i){
        printf("%d %d %d\n", res[i].i, res[i].j, res[i].k);
    }
}
int main(){	
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        scanf("%s", s[i] + 1);
    }
    solve();
    return 0;
}