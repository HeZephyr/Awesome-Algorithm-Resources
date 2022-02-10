/**
  *@filename:H
  *@author: pursuit
  *@created: 2021-08-07 12:23
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,x;
int num[N],tot,cnt[N];
void solve(){
    ll ans = 0;
    sort(num + 1,num + 1 + tot);
    for(int i = 1; i <= tot; ++ i){
        for(int j = 1; j <= tot; ++ j){
            if(1LL * num[i] * num[j] > 1e6)break;
            ans += 1LL * cnt[num[i] * num[j]] * cnt[num[i]] * cnt[num[j]]; 
        }
    }
    printf("%lld\n", ans);
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &x);
        if(!cnt[x]){
            num[++ tot] = x;
        }
        cnt[x] ++;
    }
    solve();
    return 0;
}