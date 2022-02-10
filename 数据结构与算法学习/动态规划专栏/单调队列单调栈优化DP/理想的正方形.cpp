/**
  *@filename:理想的正方形
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-03 09:21
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000 + 5;
const int P = 1e9+7;

int a,b,n,s[N][N];
pair<int,int> q[N];
void solve(){
}
int main(){
    scanf("%d %d %d", &a ,&b, &n);
    for(int i = 1; i <= a; ++ i){
        for(int j = 1; j <= b; ++ j){
            scanf("%d", &s[i][j]);
            s[i][j] += (s[i -1][j] + s[i][j - 1] - s[i - 1][j - 1]);
        }
    }
    solve();
    return 0;
}