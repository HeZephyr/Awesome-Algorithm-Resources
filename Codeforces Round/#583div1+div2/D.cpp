#include<bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int N = 1e6 + 10;
//宝藏隐藏在(n, m)。
int n, m;
string g[N]; 
int res;
int vis[N];
bool dfs(int x, int y){
    //cout << x << " " << y << endl;
    if(x < 0 || y < 0 || x >= n || y >= m || vis[x * m + y] || g[x][y] == '#')return false;
    if(x == n - 1 && y == m - 1)return true;
    vis[x * m + y] = 1;
    return dfs(x + 1, y) || dfs(x, y + 1);
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; ++ i){
        cin >> g[i];
    }
    if(dfs(0, 0)) ++ res;
    vis[0] = false;
    if(dfs(0, 0)) ++ res;
    cout << res << endl;
    return 0;
}