#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

char s[10][10];
int ans;
bool vis[10][10];
int go[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
void dfs(int i, int j){
    vis[i][j] = true;
    if(s[i][j] == '#'){
        ++ ans;
    }
    for(int k = 0; k < 4; ++ k){
        int x = i + go[k][0], y = j + go[k][1];
        if(x >= 0 && x < 2 && y >= 0 && y < 2 && s[x][y] == '#' && !vis[x][y]){
            dfs(x, y);
        }
    }
}
int main(){
    scanf("%s%s", s[0], s[1]);
    int cnt = 0;
    for(int i = 0; i < 2; ++ i){
        for(int j = 0; j < 2; ++ j){
            if(s[i][j] == '#')++ cnt;
        }
    }
    bool flag = true;
    for(int i = 0; i < 2; ++ i){
        for(int j = 0; j < 2; ++ j){
            if(s[i][j] == '#'){
                ans = 0;
                memset(vis, 0, sizeof(vis));
                dfs(i, j);
                if(ans != cnt){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag)break;
    }
    if(flag)puts("Yes");
    else puts("No");
    return 0;
}