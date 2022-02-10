/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-09-02 10:41
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N], dp[N];//dp[i]表示以i结尾的最长上升子序列。
/*
认为排列是漂亮的，对于任意两个相邻的索引i_j和i_{j + 1}满足s_{i_j} < s_{i_{j + 1}}。
选择的i_j和i_{j + 1}是能被整数的。
*/
void solve(){
    int res = 1;
    for(int i = 2; i <= n; ++ i){
        for(int j = 1; j * j <= i; ++ j){
            if(i % j != 0)continue;
            if(a[j] < a[i])dp[i] = max(dp[i], dp[j] + 1);
            if(j * j != i && a[i / j] < a[i])dp[i] = max(dp[i], dp[i / j] + 1);
        }
        res = max(res, dp[i]);
    }
    printf("%d\n", res);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            dp[i] = 1;
        }
        solve();
    }
    return 0;
}