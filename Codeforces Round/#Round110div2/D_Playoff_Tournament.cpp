/**
  *@filename:D_Playoff_Tournament
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-26 19:27
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (1 << 19) + 10;
const int P = 1e9+7;

int k,q,n;//n为字符串的长度。
char s[N];
int dp[N];
void update(int rt){
    if(rt == 0)return;
    if(s[n - rt] == '0'){
        dp[rt] = dp[rt << 1 | 1];
    }
    else if(s[n - rt] == '1'){
        dp[rt] =  dp[rt << 1];
    }
    else{
        dp[rt] = dp[rt << 1] + dp[rt << 1 | 1];
    }
    update(rt / 2);
}
void solve(){
    for(int i = n; i < 2 * n; ++ i){
        dp[i] = 1;
    }
    for(int i = n - 1; i >= 1; -- i){
        //自顶向下更新。
        update(i);
    }
    int x;
    char op;
    while(q -- ){
        scanf("%d %c", &x, &op);
        s[x] = op;
        update(n - x);
        cout << dp[1] << endl;
    }
}
int main(){
    scanf("%d%s", &k,s + 1);
    n = 1 << k;
    scanf("%d", &q);
    solve();
    return 0;
}