/**
  *@filename:随机题意
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-08-01 14:08
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,k,x;
map<int,int> p;
void solve(){
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &x);
            p[x] ++;
        }
        solve();
    }
    return 0;
}