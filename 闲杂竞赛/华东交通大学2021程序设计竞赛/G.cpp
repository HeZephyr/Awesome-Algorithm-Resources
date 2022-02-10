#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e2 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, m;
char s[N][N];
bool vis[N][N];
int len;
int go[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
struct node{
    int x, y, step;
    bool operator < (const node &A){
        if(x != A.x)return x < A.x;
        return y < A.y;
    }
};
vector<node> g[6];
int a[N];
void bfs(int x, int y){
    g[len].clear();
    queue<node> q;
    memset(vis, 0, sizeof(vis));
    q.push({x, y, 0});
    vis[x][y] = true;
    node head, temp;
    while(!q.empty()){
        head = q.front();
        q.pop();
        if(s[head.x][head.y] == 'P'){
            g[len].push_back({head});
        }
        for(int i = 0; i < 4; ++ i){
            temp = head;
            temp.x += go[i][0], temp.y += go[i][1];
            temp.step ++;
            if(temp.x >= 1 && temp.x <= n && temp.y >= 1 && temp.y <= m && s[temp.x][temp.y] != 'Q' && s[temp.x][temp.y] != 'H' && 
            !vis[temp.x][temp.y]){
                q.push(temp);
                vis[temp.x][temp.y] = true;
            }
        }
    }
}
void solve(){
    len = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            if(s[i][j] == 'C'){
                bfs(i, j);
                ++ len;
            }
        }
    }
    if(len == 0){
        puts("0");
        return;
    }
    for(int i = 0; i < len; ++ i){
        sort(g[i].begin(), g[i].end());
    }
    int len1 = g[0].size();
    for(int i = 0; i < len1; ++ i)a[i] = i;
    int res = INF;
    do{
        int cnt = 0;
        for(int i = 0; i < len; ++ i){
            //cout << a[i] << " " << g[i][a[i]].step << endl;
            cnt += g[i][a[i]].step;
        }
        res = min(res, cnt);
    }while(next_permutation(a, a + len1));
    printf("%d\n", res);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++ i){
            scanf("%s", s[i] + 1);
        }
        solve();
    }
    return 0;
}