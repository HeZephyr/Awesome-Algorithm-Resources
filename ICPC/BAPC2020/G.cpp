/**
  *@filename:G
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-30 14:35
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5;
const int P = 1e9+7;

int n;
string s;
vector<string> g[N];
bool vis[N];
bool flag;
void solve(){
    int idx = 0;
    for(int i = 1; i <= n; ++ i){
        if(vis[i]){
            idx = i;
            break;
        }
    }
    cout << g[idx].size() << endl;
    for(auto &s : g[idx]){
        cout << s << endl;
    }
}
int main(){
    cin >> n;
    int x;
    for(int i = 1; i <= n; ++ i){
        cin >> x;
        flag = false;
        while(x -- ){
            cin >> s;
            if(s.size() > 20){
                flag = true;
            }
            g[i].push_back(s);
        }
        if(!flag){
            vis[i] = true;
        }
    }
    solve();
    return 0;
}