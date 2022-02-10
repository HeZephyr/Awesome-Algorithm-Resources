/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-09-10 15:57
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl
#define x first 
#define y second

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 50 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//创建最多一条隧道的最低成本。以便可以从(r1, c1)到达(r2, c2)。
int n;
char s[N][N];//如果为陆地则为0，否则为1。
int go[4][2] = {0, 1, 1, 0, 0, -1, -1, 0}, minn;
bool vis[N][N];
pii st, ed;
queue<pii> q;
int distance(pii st, pii ed){
    return (st.x - ed.x) * (st.x - ed.x) + (st.y - ed.y) * (st.y - ed.y);
}
void bfs(pii x, vector<pii> &a){
    pii u, v;
    q.push(x);
    while(!q.empty()){
        u = q.front();
        a.push_back(u);
        q.pop();
        vis[u.x][u.y] = true;
        for(int i = 0; i < 4; ++ i){
            v.x = u.x + go[i][0], v.y = u.y + go[i][1];
            if(v.x >= 1 && v.x <= n && v.y >= 1 && v.y <= n && s[v.x][v.y] == '0' && !vis[v.x][v.y]){
                q.push(v);
            }
        }
    }
}
void solve(){
    //枚举所建隧道。
    //直接bfs。碰到不行的就退出。每到一个点取min。
    minn = INF;
    vector<pii> a, b;
    bfs(st, a), bfs(ed, b);
    for(auto u : a){
        //cout << u.x << " " << u.y << endl;
        for(auto v : b){
            minn = min(minn, distance(u, v));
        }
    }
    cout << minn << endl;
}
int main(){	
    cin >> n;
    cin >> st.x >> st.y >> ed.x >> ed.y;
    for(int i = 1; i <= n; ++ i){
        cin >> s[i] + 1;
    }
    solve();
    return 0;
}