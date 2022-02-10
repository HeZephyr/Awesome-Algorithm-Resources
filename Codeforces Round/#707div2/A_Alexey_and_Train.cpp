/**
  *@filename:A_Alexey_and_Train
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-11 09:55
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5;
const int P = 1e9+7;

int t,n,a[N],b[N],tm_et[N];//a[i]是预期到达i站的时间，b[i]是从第i站预期出发的时间,tm[i]则是所需的额外时间。
void solve(){
    //根据题意，需要满足这些条件，所以我们取最大值累加即可。
    int ans = 0;//为达到i - 1站所花的时间。
    for(int i = 1; i < n; ++ i){
        int temp = ans + a[i] - b[i - 1] + tm_et[i] + (b[i] - a[i] + 1) / 2;
        ans = max(temp,b[i]);
    }
    ans += a[n] - b[n - 1] + tm_et[n];
    printf("%d\n",ans);
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d%d", &a[i], &b[i]);
        }
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &tm_et[i]);
        }
        solve();
    }
    return 0;
}