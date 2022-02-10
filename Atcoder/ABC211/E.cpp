/**
  *@filename:E
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-25 11:17
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,k,ans;
vector<string> s;
int go[4][2] = {0,1,0,-1,1,0,-1,0};
map<vector<string>,int> p;//去重。
bool flag;
void dfs(int num){
    //从(x,y)出现，还剩k个需要染色。
    if(p[s]){
        return;
    }
    p[s]++;
    if(num == 0){
        /* for(int i = 0; i < s.size(); ++ i){
            cout << s[i] << endl;
        }
        cout << endl; */
        ans ++;
        return;
    }
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < n; ++ j){
            if(s[i][j] == '.'){
                for(int c = 0; c < 4; ++ c){
                    int dx = i + go[c][0],dy = j + go[c][1];
                    if(dx >= 0 && dx < n && dy >= 0 && dy < n && s[dx][dy] == 'r'){
                        s[i][j] = 'r';
                        dfs(num - 1);
                        s[i][j] = '.';
                    }
                }
            }
        }
    }
}
void solve(){
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < n; ++ j){
            if(s[i][j] == '.'){
                s[i][j] = 'r';
                dfs(k - 1);
                s[i][j] = '.';
            }
        }
    }
    cout << ans << endl;
}
int main(){
    cin >> n >> k;
    s.resize(n);
    for(int i = 0; i < n; ++ i){
        cin >> s[i];
    }
    solve();
    return 0;
}