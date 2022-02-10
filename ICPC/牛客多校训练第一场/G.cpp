/**
  *@filename:G
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-20 01:27
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 500000 + 5;
const int P = 1e9+7;

int n,k;
int a[N],b[N];
void solve(){
}
int main(){
    scanf("%d%d", &n, &k);
    ll ans = 0;
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &b[i]);
        if(a[i] > b[i])swap(a[i],b[i]);//这里保证为区间[ai,bi]
        ans += abs(a[i] - b[i]);
    }
    if(n == 2){
        //特判n = 2的情况，此时必须要交换。
        if(k & 1){
            ans = abs(a[1] - b[2]) + abs(a[2] - b[1]);
        }
        else{
            ans = abs(a[1] - b[1]) + abs(a[2] - b[2]);
        }
    }
    else{
        //而n > 2的时候，我们注意到，我们可以进行无意义的操作来实现不交换的场景，所以我们只要最大化进行完最优的交换即可。
        sort(a + 1, a + 1 + n, greater<int>() );
        sort(b + 1, b + 1 + n);
        for(int i = 1; i <= k && i <= n; ++ i){
            if(a[i] > b[i]){
                ans += 2 * (a[i] - b[i]);//也就是说，min里面最大的那个比max里面最小的那个大，此时我们可以交换使得多贡献了2倍。
            }
            else{
                break;
            }
        }
    }
    printf("%lld\n", ans);
    solve();
    return 0;
}