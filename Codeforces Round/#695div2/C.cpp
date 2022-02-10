/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-09-04 15:34
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 3e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

ll a[3][N], len[3];
ll sum[3];
void solve(){
    ll sub = min({sum[0], sum[1], sum[2], a[0][1] + a[1][1], a[0][1] + a[2][1], a[1][1] + a[2][1]});
    printf("%lld\n", sum[0] + sum[1] + sum[2] - 2 * sub);
}
int main(){
    scanf("%lld%lld%lld", &len[0], &len[1], &len[2]);
    for(int i = 0; i < 3; ++ i){
        for(int j = 1; j <= len[i]; ++ j){
            scanf("%lld", &a[i][j]);
            sum[i] += a[i][j];
        }
        sort(a[i] + 1, a[i] + 1 + len[i]);
    }	
    solve();
    return 0;
}