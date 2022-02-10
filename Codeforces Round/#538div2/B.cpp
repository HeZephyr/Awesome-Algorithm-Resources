/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-16 14:19
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m,k;
bool vis[N];//判断是否为前k * m大。
int a[N],pos[N];
bool cmp(int i,int j){
    return a[i] > a[j];
}
void solve(){
    //我们贪心分组自然能获取前k * m大的元素。
    sort(pos + 1,pos + 1 + n,cmp);
    ll ans = 0;
    for(int i = 1; i <= k * m; ++ i){
        ans += a[pos[i]];
        vis[pos[i]] = true;
    }
    printf("%lld\n", ans);
    int cnt = 0;
    for(int i = 1; i <= n; ++ i){
        cnt += vis[i];
        if(cnt == m && k > 1){
            printf("%d ", i);
            cnt = 0;
            k --;
        }
    }
    puts("");
}
int main(){	
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        pos[i] = i;
    }
    solve();
    return 0;
}