/**
  *@filename:猎人杀
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-31 14:45
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 55 + 5;
const int P = 1e9+7;

int t,n;
int ans;
bool vis[N];
int root;//root代表狼人。
vector<int> g[N];
void solve(){
    bool flag = false;
    //晚上。
    int temp;
    for(auto x : g[root]){
        if(!vis[x]){
            temp = x;
            vis[x] = true;//说明已死亡。
            ans --;
            break;
        }
    }
    if(temp == root){
        //说明狼人死亡。
        cout << "lieren" << endl;
        return;
    }
    while(true){
        if(ans <= 2){
            flag = true;
            break;
        }
        //白天。
        for(auto x : g[temp]){
            if(!vis[x]){
                vis[x] = true;
                temp = x;
                ans --;
                break;
            }
        }
        if(temp == root){
            break;
        }
    }
    if(flag){
        cout << "langren" << endl;
    }
    else{
        cout << "lieren" << endl;
    }
}
int main(){
    cin >> t;
    while(t -- ){
        memset(vis,0,sizeof(vis));
        cin >> n;
        ans = n;
        int x;
        for(int i = 1; i <= n; ++ i){
            cin >> x;
            if(x){
                root = i;//找到狼人的位置。
            }
            g[i].clear();
        }
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= n; ++ j){
                cin >> x;
                g[i].push_back(x);
            }
        }
        solve();
    }
    return 0;
}