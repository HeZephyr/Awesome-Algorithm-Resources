/**
  *@filename:C_Ball_in_Berland
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-08 09:22
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,a,b,k;
pii g[N];
int cnta[N],cntb[N];
void solve(){
    ll sum = 0;
    for(int i = 1; i <= k; ++ i){
        //有k对。我们需要去掉会影响的,因为选择了第i对，所以包含它们的其他对都作废。
        sum += k - (cnta[g[i].first] + cntb[g[i].second] - 1);
    }
    printf("%lld\n", sum / 2);
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d %d %d", &a, &b, &k);
        memset(cnta,0,sizeof(cnta));
        memset(cntb,0,sizeof(cntb));
        for(int i = 1; i <= k; ++ i){
            scanf("%d", &g[i].first);
            cnta[g[i].first] ++;
        }
        for(int i = 1; i <= k; ++ i){
            scanf("%d", &g[i].second);
            cntb[g[i].second] ++;
        }
        solve();
    }
    return 0;
}