/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-12 18:58
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,k;
int a[N];
vector<int> temp[110];
void solve(){
    for(int i = 1; i <= n; ++ i){
        temp[i].push_back(n + 1);
    }
    int minn = 0x3f3f3f3f;
    int cnt = 0;
    for(int i = 1; i <= 100; ++ i){
        
    }
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n ,&k);
        for(int i = 1; i <= n; ++ i){
            temp[i].clear();
            temp[i].push_back(0);
        }
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            temp[a[i]].push_back(i);
        }
        solve();
    }
    return 0;
}