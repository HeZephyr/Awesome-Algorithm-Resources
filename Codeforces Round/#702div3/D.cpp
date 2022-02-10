/**
  *@filename:D
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-07 08:49
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5;
const int P = 1e9+7;

int t,n,a[N];
int root[N];
void dfs(int l,int r,int step){
    int maxx = 0,idx = 0;
    for(int i = l; i <= r; ++ i){
        if(a[i] > maxx){
            maxx = a[i];
            idx = i;
        }
    }
    if(idx != 0){
        root[idx] = step;
        dfs(l,idx - 1,step + 1);
        dfs(idx + 1,r,step + 1);
    }
}
void solve(){
    //先找到树根。
    for(int i = 1; i <= n; ++ i){
        if(a[i] == n){
            root[i] = 0;
           dfs(1,i - 1,1);
           dfs(i + 1,n,1);
            break; 
        }
    }
    for(int i = 1; i <= n; ++ i){
        cout << root[i] << " ";
    }
    cout << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
        }
        solve();
    }
    return 0;
}