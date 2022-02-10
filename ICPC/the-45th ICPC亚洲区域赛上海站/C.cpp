/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-10-07 20:18
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int a[32], b[32];
int t, x, y;
int dp[32][2][2][2];
int dfs(int pos, bool flagA, bool flagB, bool ok){
    //pos表示当前正在处理的位，flagA表示是否限定了x的上界，flagB表示是否限定了y的上界。ok表示枚举的值目前是否为0。
    if(pos == -1)return 1;
    int &x = dp[pos][flagA][flagB][ok];
    if(x != -1)return x;
    int upA = flagA ? a[pos] : 1, upB = flagB ? b[pos] : 1;
    int ans = 0, cnt;
    //cout << pos << " " << flagA << " " << flagB << " " << ok << endl;
    for(int i = 0; i <= upA; ++ i){
        for(int j = 0; j <= upB; ++ j){
            if(i & j)continue;
            if(ok && (i || j)){
                //说明当前确定了最高位。
                cnt = pos + 1;
            }
            else{
                //如果不是最高位，则将其设置为1，并统计方案数。
                cnt = 1;
            }
            ans = (ans + 1LL * dfs(pos - 1, flagA && i == upA, flagB && j == upB, ok && !i && !j) * cnt % P) % P;
        }
    }
    return x = ans;
}
void solve(){
    int len = 0;
    memset(dp, -1, sizeof(dp));
    for(int i = 31; i >= 0; -- i){
        a[i] = (x >> i) & 1, b[i] = (y >> i) & 1;
        if(a[i] || b[i])len = max(len, i);
    }
    int res = dfs(len, 1, 1, 1);
    printf("%d\n", (res - 1 + P) % P);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &x, &y);
        solve();
    }
    return 0;
}