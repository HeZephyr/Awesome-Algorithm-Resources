/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-20 01:03
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5000 + 5;
const int P = 1e9+7;

bool dp[N][N];
int t,n,m;
//找到所有必败态。
void cal(int n,int m){
    for(int k = 1; n + k < N; ++ k){
        for(int s = 0; m + s * k < N; ++ s){
            dp[n + k][m + s * k] = 1;//由于能转到必败态，所以这种情况必赢。
        }
    }
    for(int k = 1; m + k < N; ++ k){
        for(int s = 0; n + s * k < N; ++ s){
            dp[n + s * k][m + k] = 1;//由于能转到必败态，所以这种情况必赢。
        }
    }
}
void init(){
    //此为我们所知的必败态。
    cal(0,0);
    for(int i = 1; i < N; ++ i){
        for(int j = 0; j < N; ++ j){
            if(!dp[i][j]){
                cal(i,j);
            }
        }
    }
}
void solve(){
    printf("%s\n",dp[n][m] ? "Alice" : "Bob");
}
int main(){
    init();
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &m);
        solve();
    }
    return 0;
}